class Solution {
public:
        vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
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
        reverse(ans.begin(), ans.end());
        if(ans.size()!=V)return {};
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return topoSort(numCourses, prerequisites);
    }
};