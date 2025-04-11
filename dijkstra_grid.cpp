#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &a)
    {
        vector<vector<int>> d(a.size(), vector<int>(a[0].size(), INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        d[0][0] = 0;
        while (!pq.empty())
        {
            int w = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int dd = d[i][j];
            if (i == a.size() - 1 && j == a[0].size() - 1)
            {
                return d[i][j];
            }
            if (i + 1 < a.size())
            {
                if (d[i + 1][j] > max(abs(a[i + 1][j] - a[i][j]), dd))
                {
                    d[i+1][j] = max(abs(a[i + 1][j] - a[i][j]), dd);
                    pq.push({max(abs(a[i + 1][j] - a[i][j]), dd), {i + 1, j}});
                }
            }
            if (j + 1 < a[0].size())
            {
                if (d[i][j + 1] > max(abs(a[i][j + 1] - a[i][j]), dd))
                {
                    d[i][j + 1] = max(abs(a[i][j + 1] - a[i][j]), dd);
                    pq.push({max(abs(a[i][j + 1] - a[i][j]), dd), {i, j + 1}});
                }
            }
            if (i - 1 >= 0)
            {
                if (d[i - 1][j] > max(abs(a[i - 1][j] - a[i][j]), dd))
                {
                    d[i - 1][j] = max(abs(a[i - 1][j] - a[i][j]), dd);
                    pq.push({max(abs(a[i - 1][j] - a[i][j]), dd), {i - 1, j}});
                }
            }
            if (j - 1 >= 0)
            {
                if (d[i][j - 1] > max(abs(a[i][j - 1] - a[i][j]), dd))
                {
                    d[i][j - 1] = max(abs(a[i][j - 1] - a[i][j]), dd);
                    pq.push({max(abs(a[i][j - 1] - a[i][j]), dd), {i, j - 1}});
                }
            }
        }
    }
};