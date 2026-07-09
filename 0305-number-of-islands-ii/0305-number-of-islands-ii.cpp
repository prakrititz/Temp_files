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
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int>ans;
        vector<int>parent(n*m, -1);
        vector<int>rank(n*m, 0);
        int cnt = 0;
        vector<pair<int, int>>dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(auto it:positions)
        {
            int r = it[0];
            int c = it[1];
            if(parent[r*n+c]!=-1){
                ans.push_back(cnt);
                continue;
            }
            parent[r*n+c]=r*n+c;
            cnt++;
            for(auto it:dir)
            {
                int nr = r+it.first;
                int nc = c+it.second;
                if(nr<m && nc<n && nr>=0 && nc>=0 && parent[nr*n+nc]!=-1)
                {
                    int p_curr = find_parent(parent, r*n+c);
                    int p_n = find_parent(parent, nr*n+nc);
                    if(p_curr!=p_n)
                    {
                        uni(parent, rank, p_curr, p_n);
                        cnt--;
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};