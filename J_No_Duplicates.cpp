#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Function to compute the number of valid sequences
vector<long long> solve(int n, int m, int q, vector<pair<int, int>>& restrictions) {
    vector<long long> dp(q + 1, 0);
    dp[0] = 1; // Base case: no restrictions, 1 valid sequence (empty sequence)

    for (int i = 1; i <= q; ++i) {
        int l = restrictions[i - 1].first;
        int r = restrictions[i - 1].second;
        int len = r - l + 1;

        // Calculate the number of ways to assign distinct values to the subarray
        long long ways = 1;
        for (int j = 0; j < len; ++j) {
            ways = (ways * (m - j)) % MOD;
        }

        // Multiply by the number of ways to assign values to the rest of the sequence
        ways = (ways * dp[i - 1]) % MOD;

        dp[i] = ways;
    }

    // Remove the base case (dp[0]) from the result
    return vector<long long>(dp.begin() + 1, dp.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<pair<int, int>> restrictions(q);
        for (int i = 0; i < q; ++i) {
            cin >> restrictions[i].first >> restrictions[i].second;
        }

        // Solve for this test case
        vector<long long> result = solve(n, m, q, restrictions);

        // Output the results
        for (long long res : result) {
            cout << res << "\n";
        }
    }

    return 0;
}