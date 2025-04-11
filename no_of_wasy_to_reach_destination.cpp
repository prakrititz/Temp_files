#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        int n = adj.size();
        vector<int> d(n, LLONG_MAX);
        vector<int> ways(n, 0);
        d[src] = 0;
        ways[src] = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (dist > d[node])
                continue;
            for (auto it : adj[node])
            {
                int neighbor = it.first;
                int weight = it.second;

                if (d[node] + weight < d[neighbor])
                {
                    d[neighbor] = d[node] + weight;
                    pq.push({d[neighbor], neighbor});
                    ways[neighbor] = ways[node];
                }
                else if (d[node] + weight == d[neighbor])
                {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }

    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]}); // Make it undirected
        }
        int count = dijkstra(adj, 0);
        return count;
    }
};
class Solution {
    public:
        const int MOD = 1e9 + 7;
        
        int dijkstra(vector<vector<pair<int, int>>> &adj, int src, int n) {
            vector<long long> d(n, LLONG_MAX); // Use long long to avoid integer overflow
            vector<int> ways(n, 0);
            d[src] = 0;
            ways[src] = 1;
            
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            pq.push({0, src});
            
            while (!pq.empty()) {
                long long dist = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                
                if (dist > d[node]) continue; // Skip if we have already found a shorter path
                
                for (auto &it : adj[node]) { 
                    int neighbor = it.first;
                    int weight = it.second;
    
                    if (d[node] + weight < d[neighbor]) { 
                        d[neighbor] = d[node] + weight;
                        pq.push({d[neighbor], neighbor});
                        ways[neighbor] = ways[node]; // Reset ways to current path count
                    }
                    else if (d[node] + weight == d[neighbor]) { // If another shortest path is found
                        ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                    }
                }
            }
            return ways[n - 1];
        }
    
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int, int>>> adj(n);
            
            // Construct adjacency list
            for (const auto &road : roads) {
                adj[road[0]].push_back({road[1], road[2]});
                adj[road[1]].push_back({road[0], road[2]});
            }
            
            return dijkstra(adj, 0, n);
        }
    };