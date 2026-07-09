class Solution {
    public:
    int timer = 0; 
    vector<vector<int>>ans;
    void dfs(int curr, vector<vector<int>>& adj, vector<int>& vis, vector<int>& tin, vector<int>&low, vector<int>&parent) {
        tin[curr] = timer++;
        low[curr] = tin[curr];
        for(auto it:adj[curr])
        {
            if(it == parent[curr])continue;
            if(!vis[it])
            {
                parent[it] = curr;
                vis[it] = 1;
                dfs(it, adj, vis, tin, low, parent);
                if(low[it]>tin[curr])
                {
                    ans.push_back({it, curr});
                }
            }
            low[curr] = min(low[curr], low[it]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
      vector<int>vis(n,0);
      vector<int>tin(n, 0);
      vector<int>dp(n, INT_MAX); // lowest tin of surrounding
      vector<int>parent(n, 0);
      parent[0]= -1;
      vector<vector<int>>adj(n);
      for(auto it:connections)
      {
        int u= it[0];
        int v =it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      vis[0]= 1;
      dfs(0,adj,vis, tin, dp, parent);
      return ans;
    }
};