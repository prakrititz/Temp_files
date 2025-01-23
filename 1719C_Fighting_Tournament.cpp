#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterPosition(const vector<pair<int, int>>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;
    st.push(0);
    for(int i = 1; i < n; i++) {
        while(!st.empty() && arr[i].first > arr[st.top()].first) {
            result[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return result;
}
void solve() {
    int n, q;
    cin>>n>>q;
    vector<int>a(n);
    vector<pair<int, int>>p;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        p.push_back({a[i], i+1});
    }
    vector<int>maxi(n);
    maxi[0] = a[0];
    for (int i = 1; i < n; i++) {
        maxi[i] = max(maxi[i-1], a[i]);
    }
    vector<int>next  = nextGreaterPosition(p);
    vector<int>first_n_rounds(n);
    while(q--)
    {
        int i, k;
        cin>>i>>k;
        i--;
        if(a[i]==maxi[n-1])//if largest  will win all the rounds
        {
            if(i<=1)cout<<k<<endl;//if will all the rounhnds
            else{
                cout<<max(0,k-(i-1))<<endl; // wont win untill  its turn arrives then win infinitely
            }
        }
        else
        {
            if(a[i]!=maxi[i])cout<<0<<endl;
            else{
                int will_lose = next[i];//next greater
                int wins_after = max(0, next[i]-i-1);
                int round_needed = 0;                
                int wins_before = 0;
                if(i>1)
                {
                    k -= i-1;
                    if(k<=0)cout<<0<<endl;
                    else{
                        wins_before++;
                        k--;
                        if(k==0)cout<<wins_before<<endl;
                        else{
                            cout<<wins_before + min(k,wins_after)<<endl;
                        }
                    }
                }
                else{
                    if(i==0)cout<<min(k, wins_after)<<endl;
                    else{
                        k--;
                        wins_before++;
                        cout<<wins_before + min(k,wins_after)<<endl;
                    }
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}