class Solution {
public:
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n);
        for(int i =0;i<n;i++){
            parent[i] = i;
        }
        vector<int>rank(n, 1);
        for(auto it:edges)
        {
            int u = it[0]-1;
            int v = it[1]-1;
            if(uni(parent, rank, u, v))return it;
        }
        return {};
    }
};