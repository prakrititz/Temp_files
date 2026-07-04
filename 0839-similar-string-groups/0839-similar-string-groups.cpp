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
        //
        int pu = find_parent(parent, u);
        int pv = find_parent(parent, v);
        if(rank[pv]==rank[pu])
        {
            parent[pv] = pu;
            rank[pu] += 1;
        }
        else if(rank[pv] > rank[pu]){
            parent[pu] = pv;
            rank[pv] = rank[pu];
        }
        else 
        {
            parent[pv] = pu;
            rank[pv] = rank[pu];
        }
    }
    bool check(string a, string b, int m)
    {
        int diff = 0;
        for(int i = 0;i<m;i++)
        {
            if(a[i]!=b[i])diff++;
        }
        if(diff<=2)return true;
        return false;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int>parent(n);
        for(int i = 0;i<n;i++)parent[i] = i;
        vector<int>rank(n,1);
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i!=j&& check(strs[i], strs[j], m))
                {
                    uni(parent, i , j, rank);
                }
            }
        }
        int cnt= 0;
        for(int i = 0;i<n ;i++)if(parent[i]==i)cnt++;
        return cnt;
    }
};