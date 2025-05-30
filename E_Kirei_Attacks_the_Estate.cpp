#include <bits/stdc++.h>
using namespace std;
void dfs(long long node, vector<vector<long long>> &g, vector<long long> &vis, vector<long long> &a, vector<long long> &par, vector<long long> &val, int parent = -1)
{
    vis[node] = true;
    if (parent == -1)
    {
        val[node] = a[node];
        par[node] = a[node];
    }
    else
    {
        val[node] = max(a[node], a[node] - par[parent]);
        par[node] = min(a[node], a[node] - val[parent]);
    }
    for (auto it : g[node])
    {
        if (!vis[it])
        {
            dfs(it, g, vis, a, par, val, node);
        }
    }
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<long long>> g(n);
    for (long long i = 0; i < n - 1; i++)
    {
        long long x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<long long> vis(n, false);
    vector<long long> par(n);
    vector<long long> val(n);
    dfs(0, g, vis, a, par, val);
    for (long long i = 0; i < n; i++)
        cout << val[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}