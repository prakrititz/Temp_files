#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void bfs(int start, vector<vector<int>> &tree, vector<pair<int, int>> &dist_nodes)
{
    vector<int> distance(tree.size(), 0);
    queue<int> q;

    q.push(start);
    distance[start] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        dist_nodes.push_back({distance[curr], curr});

        for (int child : tree[curr])
        {
            distance[child] = distance[curr] + 1;
            q.push(child);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    vector<int> parent(n + 1, 0);

    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
        tree[parent[i]].push_back(i);
    }

    vector<int> dp(n + 1, 0);
    vector<int> level_sum(n + 1, 0);

    vector<pair<int, int>> dist_nodes;
    bfs(1, tree, dist_nodes);

    sort(dist_nodes.begin(), dist_nodes.end());

    int result = 0;

    for (int i = 0; i < dist_nodes.size(); i++)
    {

        int dist = dist_nodes[i].first;
        int node = dist_nodes[i].second;

        if (node == 1)
        {
            dp[node] = 1;
        }
        else if (dist == 2)
        {
            dp[node] = 1;
        }
        else
        {
            dp[node] = (level_sum[dist - 1] - dp[parent[node]] + MOD) % MOD;
        }

        level_sum[dist] = (level_sum[dist] + dp[node]) % MOD;
        result = (result + dp[node]) % MOD;
    }

    cout << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}