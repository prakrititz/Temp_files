class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<int>&vis, int curr)
    {
        vis[curr] = 1;
        for(auto it:adj[curr])
        {
            if(!vis[it])dfs(adj, vis, it);
        }
    }
    int find_parent(vector<int>&parent, int u)
    {
        while(u!=parent[u])
        {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }
        return u;
    }
    bool uni(vector<int>&parent, vector<int>&rank,  int u, int v)
    {
        int pv = find_parent(parent, v);
        int pu = find_parent(parent, u);
        if(pv == pu)return true;
        if(rank[pv]==rank[pu])
        {
            parent[pv] = pu;
            rank[pu]++;
        }
        else if(rank[pv]>rank[pu])
        {
            parent[pu] = pv;
        }
        else{
            parent[pv] = pu;
        }
        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>indeg(n, 0);
        vector<int>rank(n, 1);
        vector<int>parent(n, 0);
        vector<vector<int>>x(n);
        vector<vector<int>>adj(n);
        for(int i = 0;i<n;i++)parent[i] = i;
        for(auto it:edges)
        {
            int u = it[0]-1;
            int v = it[1]-1;
            adj[u].push_back(v);
            x[v].push_back(u);
            indeg[v]++;
        }
        vector<int>visited(n, 0);
        for(int i = 0;i<n;i++)
        {
            if(indeg[i]==2)
            {
                dfs(adj, visited, i);
                if(visited[x[i][0]]){
                    return {x[i][0]+1, i+1};
                }
                else{
                    return {x[i][1]+1, i+1};
                }
            }
        }
        for(auto it:edges)
        {
            int u = it[0]-1;
            int v = it[1]-1;
            if(uni(parent, rank, u, v))return it;
        }
        return {};
    }
};