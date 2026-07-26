class Solution {
    public:
    int timer = 0; 
    vector<vector<int>>ans;
    void dfs(int curr, vector<vector<int>>&adj, vector<int>&vis, vector<int>&t, vector<int>&dp, int parent)
    {
        vis[curr] = 1;
        t[curr] = timer;
        timer++;
        dp[curr] = t[curr];
        for(auto it:adj[curr])
        {
            if(it==parent)continue;
            if(!vis[it]) {
                dfs(it, adj, vis, t, dp, curr);
                if(dp[it]>t[curr]) ans.push_back({it, curr});
            }
            dp[curr] = min(dp[curr], dp[it]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
      vector<int>vis(n,0);
      vector<int>tin(n, 0);
      vector<int>dp(n, INT_MAX); 
      vector<vector<int>>adj(n);
      for(auto it:connections)
      {
        int u= it[0];
        int v =it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      vis[0]= 1;
      dfs(0,adj,vis, tin, dp, -1);
      return ans;
    }
};