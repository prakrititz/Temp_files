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
int ford_fulkerson(vector<vector<pair<int, int>>> &adj, int s, int t)
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
        int flow = dfs(adj, capacity, parent, s, t, INT_MAX);
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