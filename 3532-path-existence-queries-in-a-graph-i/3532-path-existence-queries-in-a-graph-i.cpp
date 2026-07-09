class Solution {
public:
    int find_parent(vector<int>&parent, int x)
    {
        while(x!=parent[x])
        {
            parent[x]= parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void uni(vector<int>&parent,vector<int>&rank, int u, int v)
    {
        int pu = find_parent(parent, u);
        int pv = find_parent(parent, v);
        if(pu == pv)return;
        if(rank[pu]==rank[pv])
        {
            parent[pv] = pu;
            rank[pu] +=1;
        }
        else if(rank[pv]>rank[pu])
        {
            parent[pu] = pv;
        }
        else{
            parent[pv] = pu;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>parent(n);
        for(int i = 0;i<n;i++)parent[i]=i;
        vector<int>rank(n, 1);
        for(int i = 1;i<nums.size();i++)
        {
            if(abs(nums[i]-nums[i-1])<=maxDiff)
            {
                uni(parent, rank, i, i-1);
            }
        }
        vector<bool>ans;
        for(auto it:queries)
        {   
            int a = it[0];
            int b = it[1];
            if(find_parent(parent, a)==find_parent(parent, b))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};