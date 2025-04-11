#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
private:
    void dfs(int node, vector<vector<int>> &grph, vector<int> &vis, vector<int> &dis, int &time, vector<int> &fin, stack<int> &topoo)
    {
        vis[node] = 1;
        dis[node] = time++;
        for (auto it : grph[node])
        {
            if (!vis[it])
            {
                dfs(it, grph, vis, dis, time, fin, topoo );
            }
        }
        topoo.push(node);
        fin[node] = time++;
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> d(n);
        vector<int> f(n);
        vector<int> vis(n, 0);
        stack<int> st;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])

                dfs(i, adj, vis, d, start, f, st);
        }
        vector<int> ans(n);
        vector<pair<int, int>> ti;
        for (int i = 0; i < n; i++)
        {
            ti.push_back({f[i], i});
        }
        sort(ti.rbegin(), ti.rend());
        // Your code here
        for (int i = 0; i < n; i++)
        {
            ans[i] = ti[i].second;
        }
        /* even this works
        for(int i = 0;i<n ;i++)
        {
            ans[i] = st.top();
            st.pop();
        }
        */
        return ans;
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

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}