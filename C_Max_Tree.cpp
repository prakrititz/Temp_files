#include <bits/stdc++.h>
using namespace std;
vector<int> topo(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> d(n);
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int v : adj[i])
        {
            d[v]++;
        }
    }
    queue<int> q;
    vector<int> topo;
    for (int i = 0; i < n; i++)
    {
        if (d[i] == 0)
        {
            q.push(i);
            vis[i]++;
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!vis[adj[node][i]])
            {
                d[adj[node][i]]--;
                if (d[adj[node][i]] == 0)
                {
                    vis[adj[node][i]]++;
                    q.push(adj[node][i]);
                }
            }
        }
    }
    // reverse(topo.begin(), topo.end());
    return topo;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--, v--;
        if (x >= y)
        {
            adj[v].push_back(u);
        }
        else
        {
            adj[u].push_back(v);
        }
    }
    vector<int> t = topo(adj);
    vector<int> ans(n);
    for (int i = 1; i <= n; i++)
    {
        ans[t[i - 1]] = i;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
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