#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;
    cin>>n;
    vector<int>b;
    bool f = 0;
    map<int, int>mp;
    for(int i = 0;i<n ;i++){
        int x;
        cin>>x;
        b.push_back(x);
        mp[x]++;
    }
    int ps = -1;
    int mx = *max_element(b.begin(), b.end());
    for(int i = 0;i<n;i++){
        if(b[i]==mx && b[(i-1+n)%n]!=mx){
            ps = i;
            break;}
    }
    vector<int>a(n);
    if(ps==-1)
    {
        if(mx==0){cout<<"YES"<<endl;
            for(int i = 0;i<n;i++)cout<<n<<" ";cout<<endl;}
        else cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        int k = ps;
        a[k] = mx;
        int sum = accumulate(b.begin(), b.end(), 0LL)-mx;
        for(int i = 1;i<n;i++)
        {
            if(i>1){
                sum -= b[(k+i-1)%n];
            }
            a[(k+i)%n] = sum + 2*mx;
        }
        for(auto it:a)cout<<it<<" ";
        cout<<endl;
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}