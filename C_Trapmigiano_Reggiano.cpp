#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &grph, vector<int> &vis, vector<int> &dis, int curr_dis)
{
    vis[node] = 1;
    dis[node] = curr_dis;
    for (auto it : grph[node])
    {
        if (!vis[it])
        {
            dfs(it, grph, vis, dis, curr_dis + 1);
        }
    }
}

void solve()
{
    int n, st, en;
    cin >> n >> st >> en;
    vector adj(n + 1, vector<int>());
    vector<int> dis(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    dfs(en, adj, vis, dis, 0);
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back({dis[i], i});
    }
    sort(ans.rbegin(), ans.rend());
    for (auto it : ans)
    {
        cout << it.second << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}