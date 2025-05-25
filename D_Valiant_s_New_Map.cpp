#include <bits/stdc++.h>
using namespace std;
bool check(int &l, vector<vector<int>> &arr, int &n, int &m)
{
    vector<vector<int>> temp(n, vector<int>(m, 0));
    vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] >= l)
            {
                temp[i][j] = 1;
            }
            pre[i + 1][j + 1] = temp[i][j] + pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
        }
    }

    for (int i = 0; i <= n - l; i++)
    {
        for (int j = 0; j <= m - l; j++)
        {
            int sum = pre[i + l][j + l] - pre[i][j + l] - pre[i + l][j] + pre[i][j];
            if (sum == l * l)
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    int lo = 1;
    int hi = min(n, m);
    int ans = lo;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid, a, n, m))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
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