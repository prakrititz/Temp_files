//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V, 0);
        vector<pair<int, int>> MST;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, -1}});
        int sum = 0;
        while (!pq.empty())
        {
            // we do vis here
            int node = pq.top().second.first;
            int weight = pq.top().first;
            int parent = pq.top().second.second;
            pq.pop();
            if (vis[node])
                continue;
            vis[node] = 1;
            sum += weight;
            MST.push_back({parent, node});
            for (auto it : adj[node])
            {
                int neighbor = it[0];
                int w = it[1];
                if (!vis[neighbor])
                {
                    pq.push({w, {neighbor, node}});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
