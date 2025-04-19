#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int parent, vector<vector<int>> &grph, vector<int> &size, vector<int> &dp)
{
    vector<int> ch;
    size[node] = 1;
    for (auto it : grph[node])
    {
        if (it != parent)
        {
            size[node] += dfs(it, node, grph, size, dp);
            ch.push_back(it);
        }
    }
    if (ch.size() == 0)
    {
        dp[node] = 0;
    }
    else if (ch.size() == 1)
    {
        int child = ch[0];
        dp[node] = size[child] - 1;
    }
    else
    {
        int left = ch[0], right = ch[1];
        dp[node] = max(size[left] - 1 + dp[right],
                        size[right] - 1 + dp[left]);
    }
    return size[node];
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> size(n + 1, 0);
    vector<int> dp(n + 1, 0);

    dfs(1, -1, adj, size, dp);
    cout << dp[1] << endl;
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