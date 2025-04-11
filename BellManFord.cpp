#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<long long> dist(V, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i < V - 1; i++) {
            bool updated = false; 
            for (const auto& edge : edges) {
                int u = edge[0], v = edge[1], weight = edge[2]*1ll;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    updated = true;
                }
            }
            if (!updated) break;
        }
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};