#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void trans(vector<vector<long long>> &a)
{
    long long n = a.size();
    for (long long i = 0; i < n; i++)
    {
        for (long long j = i + 1; j < n; j++)
            swap(a[i][j], a[j][i]);
    }
}

long long cost(vector<vector<long long>> &arr, vector<long long> &a)
{
    long long n = a.size();
    vector<vector<long long>> dp(n, vector<long long>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = a[0];

    for (long long i = 1; i < n; i++)
    {
        for (long long x = 0; x < 2; x++)
        {
            for (long long y = 0; y < 2; y++)
            {
                bool ok = true;
                for (long long j = 0; j < n; j++)
                {
                    if (arr[i - 1][j] + y == arr[i][j] + x)
                        ok = false;
                }
                if (ok)
                {
                    if (x == 0)
                        dp[i][x] = min(dp[i][x], dp[i - 1][y]);
                    else
                        dp[i][x] = min(dp[i][x], dp[i - 1][y] + a[i]);
                }
            }
        }
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
}

void solve()
{
    long long n;
    cin >> n;

    vector<long long> a(n), b(n);
    vector<vector<long long>> h(n, vector<long long>(n));

    for (long long i = 0; i < n; i++)
        for (long long j = 0; j < n; j++)
            cin >> h[i][j];

    for (long long i = 0; i < n; i++)
        cin >> a[i];

    for (long long i = 0; i < n; i++)
        cin >> b[i];

    long long x = cost(h, a);
    trans(h);
    long long y = cost(h, b);

    if (x + y >= INF)
        cout << -1 << endl;
    else
        cout << x + y << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
