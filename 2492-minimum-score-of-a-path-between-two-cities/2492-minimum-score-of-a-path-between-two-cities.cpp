class Solution {
public:
    int find_parent(vector<int>&parent, int x)
    {
        while(parent[x]!=x)
        {
            parent[x]= parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void uni(vector<int>&rank , vector<int>&parent, int u, int v)
    {
        int pu = find_parent(parent, u);
        int pv = find_parent(parent, v);
        if(rank[pu] == rank[pv])
        {
            parent[pv] = pu;
            rank[pu] += 1;
        }
        if(rank[pu]> rank[pv])
        {
            parent[pv] = pu;
            rank[pv] = rank[pu];
        }
        else{
            parent[pu] = pv;
            rank[pv] = rank[pu];
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>>adj(n);
        vector<int>parent(n, 0);
        for(int i = 0;i<n;i++)parent[i] = i;
        vector<int>rank(n, 1);
        for(auto it:roads){
            int u = it[0]-1;
            int v = it[1]-1;
            uni(rank, parent, u, v);
        }
        int act_parent = find_parent(parent, 0);
        int ans = INT_MAX;
        for(auto it:roads)
        {
            int u = it[0]-1;
            int v = it[1]-1;
            if(find_parent(parent, u)==act_parent)
            {
                ans = min(ans, it[2]);
            }
        }
        return ans;
    }
};