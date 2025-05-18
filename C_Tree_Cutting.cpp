#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &grph, vector<int> &vis, vector<int> &size, int &count, int &x)
{
    vis[node] = true;
    size[node] = 1;
    for (auto it : grph[node])
    {
        if (!vis[it])
        {
            dfs(it, grph, vis, size, count, x);
            size[node] += size[it];
        }
    }
    if (size[node] >= x)
    {
        count++;
        size[node] = 0;
    }
}

bool check(int x, vector<vector<int>> adj, int k)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    vector<int> size(n, 0);
    int count = 0;
    dfs(0, adj, vis, size, count, x);
    return count > k;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int lo = 1, hi = n;
    int ans = 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid, adj, k))
        {
            lo = mid + 1;
            ans = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
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