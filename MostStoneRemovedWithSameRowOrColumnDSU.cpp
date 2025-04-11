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
        for (int i = 0; i < parent.size() - 1; i++)
        {
            if (parent[i] == i)
                ans++;
        }
        return ans;
    }
    int ToRemove()
    {
        int ans = 0;
        for (int i = 0; i < size.size() - 1; i++)
        {
            ans += size[i] - 1;
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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;

        // Find the maximum row and column index to size the DSU properly
        for (auto &stone : stones)
        {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1); // Create DSU with sufficient size

        for (auto &stone : stones)
        {
            int u = stone[0];              // Row index
            int v = stone[1] + maxRow + 1; // Offset column index to avoid overlap
            ds.unionBySize(u, v);
        }

        // Count the number of unique components (sets)
        unordered_set<int> uniqueComponents;
        for (auto &stone : stones)
        {
            int u = stone[0];
            int v = stone[1] + maxRow + 1;
            uniqueComponents.insert(ds.findParent(u)); // Count unique parents
            uniqueComponents.insert(ds.findParent(v));
        }

        return n - uniqueComponents.size();
    }
};
