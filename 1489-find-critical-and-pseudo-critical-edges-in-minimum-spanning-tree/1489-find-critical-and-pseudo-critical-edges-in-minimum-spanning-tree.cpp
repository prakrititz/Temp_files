class Solution {
public:
    static bool comp(vector<int>a, vector<int>b)
    {
        return a[2]<b[2];
    }
    int find_parent(int x, vector<int>&parent)
    {
        while(x!=parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void uni(int u, int v, vector<int>&parent, vector<int>&rank)
    {
        int pu = find_parent(u, parent);
        int pv = find_parent(v, parent);
        if(pu == pv)return;
        if(rank[pu]> rank[pv])
        {
            parent[pv]  = pu;
        }
        else if(rank[pv]>rank[pu])
        {
            parent[pu] = pv;
        }
        else{
            parent[pv] = pu;
            rank[pu] ++;
        }
    }
    int find_mst(int n, vector<vector<int>>&edges, int to_avoid, int force)
    {
        int total = 0;
        vector<int>parent(n, 0);
        vector<int>rank(n, 1);
        int cnt = 0;
        for(int i =0;i<n;i++)parent[i] = i;
        if(force<edges.size())
        {
            for(auto it:edges)
            {
                if(it[3]==force){
                    uni(it[0], it[1], parent, rank);
                    total += it[2];
                    cnt++;
                }
            }
        }
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(it[3]==to_avoid || it[3]==force)continue;
            if(find_parent(u, parent)!=find_parent(v, parent))
            {
                uni(u, v, parent, rank);
                total += wt;
                cnt++;
            }
        }
        if(cnt!=n-1)return INT_MAX;
        return total;
    }
    vector<int>critical(int n, vector<vector<int>>&edges, int mst_wt)
    {
        vector<int>ans;
        for(int i = 0;i<edges.size();i++)
        {
            if(find_mst(n, edges, i, edges.size())>mst_wt)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int>psudoCritical(int n, vector<vector<int>>&edges, int mst_wt)
    {
        vector<int>ans;
        for(int i = 0;i<edges.size();i++)
        {
            if(find_mst(n, edges, edges.size(), i)==mst_wt)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
          for(int i = 0;i<edges.size();i++)
          {
            edges[i].push_back(i);
          }
          sort(edges.begin(), edges.end(), comp);
          int Mst_wt = find_mst(n, edges, edges.size(), edges.size());
          vector<int>c = critical(n, edges, Mst_wt), p = psudoCritical(n, edges, Mst_wt);
          vector<int>x;
          for(auto it: p)
          {
            bool f = true;
            for(auto s: c)
                if(s==it)f = false;
            if(f)x.push_back(it);
          }
          return {c, x};
    }   
};