#include<bits/stdc++.h>
using namespace std;
#define int long long 
void dfs(vector<vector<int>>& adj, vector<int>& vis, int n, int p, vector<vector<int>>& dp)
{
    if (vis[n] != -1) return;
    if (adj[n].size() == 1 && p != -1)
    {
        dp[n] = {0, 1, 0};
        vis[n] = 1;
        return;
    }
    vector<vector<int>> dpx(adj[n].size() + 1, vector<int>(3, 0));
    dpx[0][0] = 1;
    int idx = 0;
    for (int it : adj[n])
    {
        if (it == p) continue;
        if (vis[it] == -1)
            dfs(adj, vis, it, n, dp);
        idx++;
        for (int x = 0; x < 3; x++)
        {
            if (!dpx[idx - 1][x]) continue;
            for (int j = 0; j < 3; j++)
            {
                if (dp[it][j])
                    dpx[idx][(x + j) % 3] = 1;
            }
        }
    }
    vis[n] = 1;
    dp[n] = dpx[idx];
    dp[n][1] = 1;
}
void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int lf = 0;
    for(int i = 0;i<adj.size();i++)
    {
        if(adj[i].size()==1)lf++;    
    }   
    vector<vector<int>> dp(n, vector<int>(3, 0));
    vector<int> vis(n, -1);
    dfs(adj, vis, 0, -1, dp);

    if (dp[0][0])
        cout << "YES"<<endl;
    else
        cout << "NO"<<endl;
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