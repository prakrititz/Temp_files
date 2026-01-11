#include<bits/stdc++.h>
using namespace std;
#define int long long 
int ans(vector<int>&a, int k){
    int n = a.size();
    map<int, int>mp;
    mp[0] = 1;
    int s = 0;
    int x = 0;
    for(int i =0;i<n; i++)
    {
        x ^= a[i];
        mp[x]++;
        if(mp.find(x^k)!=mp.end())s+=mp[x^k];
    }
    cout<<s<<endl;
}
void solve()
{
    int n, k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i = 0;i<n ;i++)cin>>a[i];
    cout<<ans(a, k)<<endl;   
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}