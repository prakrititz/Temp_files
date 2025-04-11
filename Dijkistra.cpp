#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User Function Template
class Solution {
    public:
        vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
            int n = adj.size();
            vector<int> d(n, INT_MAX);
            vector<bool> visited(n, false); // Visited array to avoid redundant processing
            d[src] = 0;
    
            // Min-heap priority queue (dista   nce, node)
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, src});
            
            while (!pq.empty()) {
                int dist = pq.top().first;
                int node = pq.top().second;
                pq.pop();
    
                if (visited[node]) continue;
                visited[node] = true;
    
                for (auto it : adj[node]) { 
                    int neighbor = it.first;  // Destination node
                    int weight = it.second;   // Edge weight
    
                    if ( d[node] + weight < d[neighbor]) { 
                        d[neighbor] = d[node] + weight;
                        pq.push({d[neighbor], neighbor});
                    }
                }
            }
            return d;
        }
    };

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}