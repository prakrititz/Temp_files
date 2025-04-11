#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int NoOfComponents()
    {
        int ans = 0;
        for(int i =0 ;i<parent.size()-1;i++)
        {
            if(parent[i]==i)ans++;
        }
        return ans;
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);
        int components = 0;
        int extra = 0;
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            if (ds.findParent(u) == ds.findParent(v))
            {
                extra++;
            }
            else
            {
                ds.unionByRank(u, v);
            }
        }
        if(extra>=ds.NoOfComponents()-1)
        {
            return ds.NoOfComponents()-1;
        }
        else{
            return -1;
        }
    }
};
int main()
{
    return 0;
}