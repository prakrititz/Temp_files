#include <bits/stdc++.h>
using namespace std;
bool check(vector<vector<pair<int, int>>> &adj, vector<int> &b, int &val)
{
    int n = adj.size();
    vector<int> dp(adj.size(), -1);
    dp[0] = b[0];
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == -1)
            continue;
        dp[i] = min(dp[i], val);
        for (auto it : adj[i])
        {
            int wt = it.second;
            int u = it.first;
            if (dp[i] < wt)
                continue;
            dp[u] = max(dp[u], dp[i] + b[u]);
        }
    }
    return dp[n - 1] != -1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> b(n);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        x--, y--;
        adj[x].push_back({y, wt}); 
    }

    int hi = 1e9;
    int lo = 1;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(adj, b, mid))
        {
            hi = mid - 1;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
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