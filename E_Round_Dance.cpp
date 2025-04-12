#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &grph, vector<bool> &vis, vector<bool> &stack)
{
    vis[node] = true;
    stack[node] = true;

    for (int neighbor : grph[node])
    {
        if (!vis[neighbor])
        {
            if (dfs(neighbor, node, grph, vis, stack))
            {
                return true;
            }
        }
        else if (stack[neighbor] && neighbor != parent)
        {
            return true;
        }
    }

    stack[node] = false;
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++)
    {
        adj[i + 1].push_back(a[i]);
        adj[a[i]].push_back(i + 1);
    }

    vector<bool> vis(n + 1, false);
    vector<bool> stack(n + 1, false);
    int cyclic_count = 0;
    int component = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            component++;
            if (dfs(i, -1, adj, vis, stack))
            {
                cyclic_count++;
            }
        }
    }
    if (cyclic_count == component)
        cout << cyclic_count << " " << component << endl;
    else
        cout << cyclic_count + 1 << " " << component << endl;
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