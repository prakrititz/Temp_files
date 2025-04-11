#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    int topologicalSort(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> d(n); // indegree
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int v : adj[i])
            {
                d[v]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        for (int i = 0; i < n; i++)
        {
            if (d[i] == 0)
            {
                q.push(i);
                vis[i]++;
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (int i = 0; i < adj[node].size(); i++)
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
        // reverse(topo.begin(), topo.end());
        return topo.size();
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj)
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}
