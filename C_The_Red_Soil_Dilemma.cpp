#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n, m, ans, cnt[maxn][maxn];
char s[maxn];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (s + 1);
        for (int j = 1; j <= m; j++) {
            if (s[j] == '1') {
                int k = j;
                while (s[k] == '1') k++;
                cnt[j][k - 1]++;
                j = k - 1; // Skip to the end of the current block of 1s
            }
        }
    }

    for (int len = m; len > 0; len--) {
        for (int l = 1, r = len; r <= m; l++, r++) {
            cnt[l][r] += cnt[l][r + 1] + cnt[l - 1][r] - cnt[l - 1][r + 1];
            ans = max(ans, (r - l + 1) * cnt[l][r]);
        }
    }

    cout << ans << endl;
    return 0;
}
