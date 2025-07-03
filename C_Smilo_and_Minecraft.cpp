#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    k--;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int t = 0;
    vector<vector<int>> g(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'g')
            {
                g[i][j] = 1;
                t++;
            }
    }
    int ans = INT_MAX;
    vector<vector<int>> pre(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pre[i][j] = g[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
            {
                int r1 = max(i - k, 0), c1 = max(j - k, 0);
                int r2 = min(i + k, n - 1), c2 = min(j + k, m - 1);
                r1++, c1++, r2++, c2++;
                ans = min(ans, pre[r2][c2] - pre[r1 - 1][c2] - pre[r2][c1 - 1] + pre[r1 - 1][c1 - 1]);
            }
        }
    }

    cout << t-ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}