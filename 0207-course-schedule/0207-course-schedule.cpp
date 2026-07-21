class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        vector<int>indeg(V, 0);
        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        for(int i = 0;i<V;i++)
        {
            if(indeg[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto it:adj[u])
            {
                indeg[it]--;
                if(indeg[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>>adj(numCourses);
       int n = numCourses;
       vector<int>ans = topoSort(n, prerequisites);
       if(ans.size()!=n)return false;
       return true;
    }
};