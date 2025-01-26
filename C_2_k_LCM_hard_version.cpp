#include <bits/stdc++.h>
using namespace std;

void solve3(vector<int>&ans, int n)
{
    if(n%2!=0)
    {
        ans.push_back(n/2);
        ans.push_back(n/2);
        ans.push_back(1);
    }
    else
    {
        int s = n/2;
        if(s%2==0)
        {
        ans.push_back(n/2);
        ans.push_back(n/4);
        ans.push_back(n/4);
        }
        else{
        int t = n/2-1;
        ans.push_back(t);
        ans.push_back(t);
        ans.push_back(2);
        }
    }
}
void solve() {
    int n; 
    int k;
    cin>>n>>k;
    vector<int>ans;
    if(k==3)
    {
        solve3(ans, n);
    }   
    else
    {
        int s = abs(k-3);
        n-=(s);
        while(s--)
        {ans.push_back(1);}
        solve3(ans, n);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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