#include <bits/stdc++.h>
using namespace std;



int dfs(int node, vector<vector<int>> &grph, vector<int> &vis, vector<int> &val)
{
    int mini = INT_MAX;
    vis[node] = true;
    // cout << "node== " << node << " " << "mini " << val[node] << endl;
    for (auto it : grph[node])
    {
        if (!vis[it])
        {
            mini = min(dfs(it, grph, vis, val), mini);
        }
    }
    if (node == 1)
    {
        if (mini == INT_MAX)
        {
            return val[node];
        }
        else
            return val[node] + mini;
    }
    if (mini == INT_MAX || mini < val[node])
    {
        return min(val[node], mini);
    }
    val[node] += (mini - val[node]) / 2;
    return val[node];
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> p(n + 1);
    for (int i = 1; i < n; i++)
    {
        cin >> p[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        adj[p[i]].push_back(i + 1);
        adj[i + 1].push_back(p[i]);
    }
    vector<int> vis(n + 1);
    int ans = dfs(1, adj, vis, a);
    cout << ans << endl;
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