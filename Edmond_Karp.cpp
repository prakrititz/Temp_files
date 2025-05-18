#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<pair<int, int>>> &grph, vector<vector<int>> &capacity, vector<int> &parent, int src, int dest, int currFlow)

{
    if (src == dest)
        return currFlow;
    for (auto it : grph[src])
    {
        int v = it.first;
        int cap = it.second;
        if (parent[v] == -1 && capacity[src][v] > 0) // if not visited and there exist a flow capacity
        {
            parent[v] = src;
            int new_flow = dfs(grph, capacity, parent, v, dest, min(currFlow, capacity[src][v]));
            if (new_flow > 0)
                return new_flow;
        }
    }
    return 0;
}
int bfs(vector<vector<pair<int, int>>> &adj, vector<vector<int>> &capacity, vector<int> &parent, int s, int t)
{
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    while (!q.empty())
    {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (auto it : adj[u])
        {
            int v = it.first;
            int flow = it.second;
            if (parent[v] == -1 && capacity[u][v] > 0)
            {
                parent[v] = u;
                int new_flow = min(flow, capacity[u][v]);
                if (v == t)
                    return new_flow;
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

int edmond_karp(vector<vector<pair<int, int>>> &adj, int s, int t)
{
    int n = adj.size();
    vector<vector<int>> capacity(n, vector<int>(n, 0));
    for (int u = 0; u < n; u++)
    {
        for (auto it : adj[u])
        {
            int v = it.first;
            int cap = it.second;
            capacity[u][v] += cap;
        }
    }
    int ans = 0;

    while (true)
    {
        vector<int> parent(n, -1);
        int flow = bfs(adj, capacity, parent, s, t);
        if (flow == 0)
        {
            break; // saturated'
        }
        ans += flow;
        int v = t;
        while (v != s)
        {
            int u = parent[u];
            capacity[u][v] -= flow;
            capacity[v][u] += flow; // updating the residue;
            v = u;
        }
    }
    return ans;
}

void solve()
{

    vector<vector<pair<int, int>>> grph;
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