#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(n + 1, 0);
    vector<vector<int>> cnt(n + 1);
    vector<int> pos(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]].push_back(i);
        pos[i] = cnt[a[i]].size() - 1;
    }
    dp[n - 1] = (a[n - 1] == 1);
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        if (pos[i] + a[i] <= cnt[a[i]].size())
        {
            int j = cnt[a[i]][pos[i] + a[i] - 1];
            dp[i] = max(dp[i], dp[j + 1] + a[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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