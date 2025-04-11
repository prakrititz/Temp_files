#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> pre(n + 1, 0);
    for (long long i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    vector<pair<long long, long long>> dp(n + 1, {INT_MIN, -1});

    for (long long i = n - k; i >= 0; i--) {
        long long sum = pre[i + k] - pre[i];
        if (sum >= dp[i + 1].first) {
            dp[i] = {sum, i + 1}; 
        } else {
            dp[i] = dp[i + 1];
        }
    }

    long long max_sum = INT_MIN, idx1 = 1, idx2 = k + 1;
    for (long long i = 0; i <= n - 2 * k; i++) {
        long long first_sum = pre[i + k] - pre[i];
        long long second_sum = dp[i + k].first;
        long long total = first_sum + second_sum;

        if (total > max_sum) {
            max_sum = total;
            idx1 = i + 1;
            idx2 = dp[i + k].second;
        }
    }

    cout << idx1 << " " << idx2 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
