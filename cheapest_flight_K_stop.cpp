#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < flights.size(); i++)
    {
        adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }
    vector<int> d(n, INT_MAX);
    queue<pair<int, pair<int, int>>> q;
    d[src] = 0;
    q.push({0, {src, 0}});
    while (!q.empty())
    {
        int node = q.front().second.first;
        int dis = q.front().second.second;
        int stops = q.front().first;
        q.pop();
        for(int i = 0;i<adj[node].size();i ++)
        {
            int neighbor = adj[node][i].first;
            int weight = adj[node][i].second;
            if(d[neighbor]>dis +weight && stops<=k)
            {
                d[neighbor] = dis+weight;
                q.push({stops+1,{neighbor, weight+dis}});
            }
        }
    }
    if (d[dst] == INT_MAX)
        return -1;
    else
        return d[dst];
}