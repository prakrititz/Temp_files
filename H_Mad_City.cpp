#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int par, const vector<vector<int>> &adj, vector<bool> &vis,
         vector<int> &p, vector<int> &cycle)
{
    vis[node] = true;
    p[node] = par;
    for (int neighbor : adj[node])
    {
        if (!vis[neighbor])
        {
            if (dfs(neighbor, node, adj, vis, p, cycle))
            {
                return true;
            }
        }
        else if (neighbor != par)
        {
            int current = node;
            while (current != neighbor)
            {
                cycle.push_back(current);
                current = p[current];
            }
            cycle.push_back(neighbor);
            return true;
        }
    }
    return false;
}

void bfs_from_cycle(const vector<int> &cycle_nodes, const vector<vector<int>> &adj,
                    vector<int> &dis, vector<int> &entry)
{
    int n = adj.size();
    vector<bool> vis(n, false);
    queue<int> q;
    for (int c : cycle_nodes)
    {
        q.push(c);
        vis[c] = true;
        dis[c] = 0;
        entry[c] = c;
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node])
        {
            if (!vis[neighbor])
            {
                vis[neighbor] = true;
                dis[neighbor] = dis[node] + 1;
                entry[neighbor] = entry[node];
                q.push(neighbor);
            }
        }
    }
}

void bfs(int start, const vector<vector<int>> &adj, vector<int> &dis)
{
    int n = adj.size();
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    dis[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node])
        {
            if (!vis[neighbor])
            {
                vis[neighbor] = true;
                dis[neighbor] = dis[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    a--;
    b--;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> vis(n, false);
    vector<int> p(n, -1);
    vector<int> cycle;
    dfs(0, -1, adj, vis, p, cycle);

    vector<int> dis(n, 0);
    vector<int> entry(n, 0);
    bfs_from_cycle(cycle, adj, dis, entry);

    int e = (dis[b] == 0 ? b : entry[b]);
    int d_V = dis[b];

    vector<int> dis_from_a(n, 0);
    bfs(a, adj, dis_from_a);
    int d_M = dis_from_a[e];
    if (d_V < d_M)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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