class Solution {
public:
    int find_parent(int a,vector<int>&parent)
    {
        int x =a;
        while(parent[x]!=x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void uni(int a, int b, vector<int>&parent, vector<int>&rank){
        int pa = find_parent(a, parent);
        int pb = find_parent(b, parent);
        if(pa == pb)return;
        if(rank[pa]>=rank[pb])
        {
            parent[pb] = pa;
            rank[pa] += rank[pb];
        }   
        else{
            parent[pa] = pb;
            rank[pb] += rank[pa];
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<int>rank(20001, 1);
        vector<int>parent(20001);
        for(int i = 0;i<parent.size();i++)parent[i] = i;
        for(auto it:stones)
        {
            int a = it[0];
            int b = it[1]+10001;
            uni(a, b, parent, rank);
        }
        unordered_set<int> unique_components;
        for(auto& stone : stones) {
            // Because row and col are unified, we only need to check the row's ultimate parent
            unique_components.insert(find_parent(stone[0], parent));
        }

        // Step 3: Total Stones - Number of Islands
        return stones.size() - unique_components.size();
    }
};