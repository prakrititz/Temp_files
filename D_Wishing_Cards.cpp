#include <bits/stdc++.h>
using namespace std;

static const long long NEG = -1e18;
void solve() {
int n, K;
    cin >> n >> K;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // dp[i][s][m]
    vector dp(n+1,
        vector(K+1, vector<long long>(K+1, NEG)));

    // dp2[s][m] — reused as prefix / suffix helper
    vector dp2(K+1, vector<long long>(K+1, NEG));

    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++) {

        /* ---------------- PREFIX DP2 ----------------
           dp2[s][b] = max(dp[i][s][0..b])
        */
        for (int s = 0; s <= K; s++) {
            long long best = NEG;
            for (int m = 0; m <= K; m++) {
                best = max(best, dp[i][s][m]);
                dp2[s][m] = best;
            }
        }

        /* ---------------- TRANSITION: m ≤ b ---------------- */
        for (int b = 0; b <= a[i]; b++) {
            for (int s = 0; s + b <= K; s++) {
                if (dp2[s][b] != NEG) {
                    dp[i+1][s+b][b] = max(
                        dp[i+1][s+b][b],
                        dp2[s][b] + b
                    );
                }
            }
        }

        /* ---------------- SUFFIX DP2 ----------------
           dp2[s][b] = max(dp[i][s][m] + m) for m > b
        */
        for (int s = 0; s <= K; s++) {
            long long best = NEG;
            for (int m = K-1; m >= 0; m--) {
                if (dp[i][s][m+1] != NEG)
                    best = max(best, dp[i][s][m+1] + (m+1));
                dp2[s][m] = best;
            }
        }

        /* ---------------- TRANSITION: m > b ---------------- */
        for (int b = 0; b <= a[i]; b++) {
            for (int s = 0; s + b <= K; s++) {
                if (dp2[s][b] != NEG) {
                    // max remains m > b
                    dp[i+1][s+b][b+1] = max(
                        dp[i+1][s+b][b+1],
                        dp2[s][b]
                    );
                }
            }
        }
    }

    long long ans = 0;
    for (int s = 0; s <= K; s++)
        for (int m = 0; m <= K; m++)
            ans = max(ans, dp[n][s][m]);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}