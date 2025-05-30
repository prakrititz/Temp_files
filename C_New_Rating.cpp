#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto func = [](int a, int b)
    {
        if (a > b)
            return a - 1;
        else if (a == b)
            return a;
        else
            return a + 1;
    };
    vector<vector<int>> dp(3, vector<int>(n + 1, 0));
    dp[1][0] = INT_MIN, dp[2][0] = INT_MIN;
    for (int i = 1; i <= n; i++)
    {

        dp[0][i] = func(dp[0][i - 1], a[i - 1]);
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1]);
        dp[2][i] = max(func(dp[1][i - 1], a[i - 1]), func(dp[2][i - 1], a[i - 1]));
    }
    cout << max(dp[2][n], dp[1][n]) << endl;
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