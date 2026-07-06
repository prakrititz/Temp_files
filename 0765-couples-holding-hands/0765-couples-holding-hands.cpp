class Solution {
public:
    int find_parent(vector<int>&parent, int x)
    {
        while(parent[x]!=x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void uni(vector<int>&parent, int u, int v, vector<int>&rank)
    {
        int pu = find_parent(parent, u);
        int pv = find_parent(parent, v);
        
        if (pu == pv) return;

        if(rank[pv]==rank[pu])
        {
            parent[pv] = pu;
            rank[pu] += 1;
        }
        else if(rank[pv] > rank[pu]){
            parent[pu] = pv;
        }
        else 
        {
            parent[pv] = pu;
        }
    }

    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < row.size(); i += 2) {
            int a = row[i] / 2;
            int b = row[i+1] / 2;
            uni(parent, a, b, rank);
        }

        int components = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i) {
                components++;
            }
        }
        
        return n - components;
    }   
};