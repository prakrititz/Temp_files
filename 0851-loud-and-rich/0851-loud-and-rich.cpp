class Solution {
public:
    int dfs(vector<vector<int>>&graph, int curr, vector<int>&ans, vector<int>&quiet)
    {
        if(ans[curr]!= -1)return ans[curr];
        int mini = quiet[curr];
        int can =  curr;
        for(auto it:graph[curr])
        {
            int candidate = dfs(graph, it, ans, quiet);
            if(mini > quiet[candidate])
            {
                mini  = quiet[candidate];
                can = candidate;
            }
        }
        return ans[curr] = can;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>>graph(n);
        vector<int>indeg(n, 0);
        vector<int>ans(n, -1);
        for(int i = 0;i<richer.size();i++)
        {
            graph[richer[i][1]].push_back(richer[i][0]);
            indeg[richer[i][0]]++;
        }
        int t;
        for(int i= 0;i<indeg.size();i++)
        {
            if(indeg[i]==0)t = dfs(graph,i, ans, quiet);
        }
        return ans;
    }
};