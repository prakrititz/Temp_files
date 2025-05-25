#include <bits/stdc++.h>
using namespace std;
long long topologicalSort(vector<vector<long long>> &adj)
{
    long long n = adj.size();
    vector<long long> d(n);
    vector<long long> vis(n, 0);
    for (long long i = 0; i < n; i++)
    {
        for (long long v : adj[i])
        {
            d[v]++;
        }
    }
    queue<long long> q;
    vector<long long> topo;
    for (long long i = 0; i < n; i++)
    {
        if (d[i] == 0)
        {
            q.push(i);
            vis[i]++;
        }
    }
    while (!q.empty())
    {
        long long node = q.front();
        q.pop();
        topo.push_back(node);
        for (long long i = 0; i < adj[node].size(); i++)
        {
            if (!vis[adj[node][i]])
            {
                d[adj[node][i]]--;
                if (d[adj[node][i]] == 0)
                {
                    vis[adj[node][i]]++;
                    q.push(adj[node][i]);
                }
            }
        }
    }
    return topo.size();
}
void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<vector<long long>> adj(n);
    while (k--)
    {
        vector<long long> temp(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> temp[i];
            temp[i]--;
        }
        for (long long i = 1; i < n - 1; i++)
        {
            adj[temp[i]].push_back(temp[i + 1]);
        }
    }
    long long x = topologicalSort(adj);
    if (x == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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