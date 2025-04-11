#include <bits/stdc++.h>
using namespace std;

void dfs(long long node, vector<vector<long long>> &grph, vector<long long> &vis)
{
    vis[node] = true;
    for (auto it : grph[node])
    {
        if (!vis[it])
        {
            dfs(it, grph, vis);
        }
    }
}

void dijkstra(vector<vector<pair<long long, long long>>> &adj, long long src, vector<long long> &d)
{
    long long n = adj.size();
    vector<bool> visited(n, false);
    d[src] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        long long dist = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;
        visited[node] = true;

        for (auto it : adj[node])
        {
            long long neighbor = it.first;
            long long weight = it.second;

            if (d[node] + weight < d[neighbor])
            {
                d[neighbor] = d[node] + weight;
                pq.push({d[neighbor], neighbor});
            }
        }
    }
}
void solve()
{
    long long n, m, h;
    cin >> n >> m >> h;
    vector<long long> hors(h);
    for (long long i = 0; i < h; i++)
    {
        cin >> hors[i];
    }
    vector<vector<pair<long long, long long>>> adj(2 * n);
    vector<vector<long long>> graph(n);
    for (long long i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        adj[u + n].push_back({v + n, w / 2});
        adj[v + n].push_back({u + n, w / 2});
    }
    for (long long i = 0; i < h; i++)
    {
        adj[hors[i] - 1].push_back({hors[i] - 1 + n, 0});
        adj[hors[i] - 1 + n].push_back({hors[i] - 1, 0});
    }
    vector<long long> d1(2 * n, LONG_LONG_MAX);
    vector<long long> d2(2 * n, LONG_LONG_MAX);
    vector<long long> vis(n, false);
    dfs(0, graph, vis);
    if (vis[n - 1] == false)
    {
        cout << -1 << endl;
        return;
    }
    dijkstra(adj, 0, d1);
    dijkstra(adj, n-1, d2);
    long long ans = LONG_LONG_MAX;
    for (long long i = 0; i < n; i++)
    {
        long long u = min(d1[i], d1[i + n]);
        long long v = min(d2[i], d2[i + n]);
        ans = min(ans, max(u, v));
    }
    cout << ans << endl;
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