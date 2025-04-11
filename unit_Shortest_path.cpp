//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Back-end complete function Template for C++

// } Driver Code Ends

class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    void bfs(int start, vector<vector<int>> &grph, vector<int> &dis)
    {
        queue<int> q;
        vector<bool> vis(grph.size(), false); // Visited array

        q.push(start);
        vis[start] = true;
        dis[start] = 0; // Distance of start node is 0

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : grph[node])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    dis[it] = dis[node] + 1;
                    q.push(it);
                }
            }
        }
    }
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        int n = adj.size();
        vector<int> ans(n, -1);
        bfs(src, adj, ans);
        return ans;
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
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}
