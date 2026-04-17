#include<bits/stdc++.h>
using namespace std;
#define int long long 
int mod = 1e9+7;
int dfs1(int node, vector<vector<int>>&a, vector<int>&v, vector<int>&size)
{
    v[node] = 1;
    size[node] = 1;
    for(auto it: a[node])
    {
        if(v[it]==0)
        {
            int t = dfs1(it, a, v, size);
            size[node]+=t;
        }
    }
    return size[node];
}
void dfs2(int node, vector<vector<int>>&a, vector<int>&v, vector<int>&size, vector<int>&ans, int val)
{
    v[node] = 1;
    ans[node] = (val+size[node])%mod;
    for(auto it: a[node])
    {
        if(v[it]==0)
        {
            dfs2(it, a, v, size, ans, ans[node]);
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>>a(n+1);
    a[0].push_back(1);
    for(int i = 1;i<=n ;i++){
        int l , r;
        cin>>l>>r;
        if(l==0 && r==0)continue;
        a[l].push_back(i);
        a[r].push_back(i);
        a[i].push_back(r);
        a[i].push_back(l);
    }
    vector<int>v(n+1, 0);
    vector<int>v2(n+1, 0);
    vector<int>size(n+1, 0);
    int x = dfs1(0, a, v, size);
    for(int i = 0;i<n+1;i++)size[i] = 2*size[i]-1;
    vector<int>ans(n+1, 0);
    
    dfs2(1, a, v2, size, ans, 0LL);
    for(int i = 1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
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
