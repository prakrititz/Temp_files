class Solution {
public:
    bool check = true;
    void dfs(int curr, vector<int>&d, vector<vector<int>>&adj, int parent)
    {
        d[curr] = 1;
        bool res = true;
        for(auto it:adj[curr])
        {
            if(d[it]==1)check =  false;
            if(d[it]==0)
            {
                dfs(it, d, adj, curr);
            }
        }
        d[curr] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>>adj(numCourses);
       int n = numCourses;
       for(auto it: prerequisites)
       {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
       }
       vector<int>d(n, 0);
       for(int i = 0;i<n;i++)
       {
            if(d[i]==0)
            {
                dfs(i, d, adj, -1);            
            }
       }
       return check;
    }
};