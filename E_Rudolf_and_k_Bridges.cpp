#include <bits/stdc++.h>
using namespace std;

long long RSQ(vector<long long> &ST, long long n, long long rangeStrt, long long rangeEnd, long long queryStrt, long long queryEnd, long long curr)
{
    if (rangeStrt > queryEnd || rangeEnd < queryStrt)
        return LLONG_MAX; 
    if (queryStrt <= rangeStrt && queryEnd >= rangeEnd)
        return ST[curr];
    long long mid = (rangeStrt + rangeEnd) / 2;
    long long m1 = LLONG_MAX;
    long long m2 = LLONG_MAX;
    if (2 * curr + 1 < 2 * n - 1)
    {
        m1 = RSQ(ST, n, rangeStrt, mid, queryStrt, queryEnd, 2 * curr + 1);
    }
    if (2 * curr + 2 < 2 * n - 1)
    {
        m2 = RSQ(ST, n, mid + 1, rangeEnd, queryStrt, queryEnd, 2 * curr + 2);
    }
    return min(m1, m2);
}

void update(vector<long long> &ST, long long array_size, long long val, long long ind)
{
    long long st_index = array_size - 1 + ind;
    ST[st_index] = val;
    long long j = (array_size - 1 + ind - 1) / 2;
    while (j >= 0)
    {
        ST[j] = min(ST[2 * j + 1], ST[2 * j + 2]);
        if (j == 0)
            return;
        else
            j = (j - 1) / 2;
    }
}

vector<long long> build(const vector<long long> &arr)
{
    long long n = arr.size();
    long long size = pow(2, ceil(log2(n)));
    vector<long long> ST(2 * size - 1, LLONG_MAX);

    for (long long i = 0; i < n; i++)
    {
        ST[size - 1 + i] = arr[i];
    }
    for (long long i = size - 2; i >= 0; i--)
    {
        ST[i] = min(ST[2 * i + 1], ST[2 * i + 2]);
    }

    return ST;
}

void solve()
{
    long long n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<long long>> grid(n, vector<long long>(m));
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            grid[i][j]++;
        }
    }
    vector<long long> sum(n);
    for (long long x = 0; x < n; x++)
    {
        vector<long long> a = grid[x];
        vector<long long> dp(m, LLONG_MAX);
        dp[0] = a[0];

        vector<long long> seg_values(m);
        seg_values[0] = dp[0];
        for (long long i = 1; i < m; i++)
        {
            seg_values[i] = LLONG_MAX;
        }
        vector<long long> ST = build(seg_values);

        for (long long i = 1; i < m; i++)
        {
            long long left = max(0LL, i - d - 1);
            long long right = i - 1;
            long long size = pow(2, ceil(log2(m)));

            long long minDP = RSQ(ST, size, 0, size - 1, left, right, 0);
            dp[i] = a[i] + minDP;

            seg_values[i] = dp[i];
            update(ST, size, dp[i], i);
        }
        sum[x] = dp[m - 1];
    }

    long long ans = LLONG_MAX;
    for (long long i = 0; i <= n - k; i++)
    {
        long long curr = 0;
        for (long long j = i; j < i + k; j++)
        {
            curr += sum[j];
        }
        ans = min(curr, ans);
    }
    cout << ans << endl;
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