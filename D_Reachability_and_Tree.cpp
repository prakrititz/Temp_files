#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &grph, vector<int> &vis, int curr, int s)
{
    vis[node] = true;
    for (auto it : grph[node])
    {
        if (!vis[it])
        {
            if (curr == 1)
            {
                cout << node + 1 << " " << it + 1 << endl;
            }
            else
            {
                cout << it + 1 << " " << node + 1 << endl;
            }
            if (it != s)
                dfs(it, grph, vis, curr * -1, s);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>
        adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s = 0;
    while (s < n && adj[s].size() != 2)
    {
        s++;
    }

    if (s == n)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> vis(n, 0);
    dfs(adj[s][0], adj, vis, 1, s);
    dfs(adj[s][1], adj, vis, -1, s);
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