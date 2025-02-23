#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    map<int, int> cnt;
    for (int num : a)
    {
        cnt[num]++;
    }

    int max_num = cnt.rbegin()->first;

    vector<long long> dp(max_num + 2, 0);
    dp[1] = cnt[1];

    for (int i = 2; i <= max_num; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + 1LL * cnt[i] * i);
    }
    cout << dp[max_num] << endl;

    return 0;
}