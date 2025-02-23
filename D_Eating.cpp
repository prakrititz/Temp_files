#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
        cin >> n >> q;
        vector<int> w(n);
        for (int i = 0; i < n; ++i)
            cin >> w[i];
        reverse(w.begin(), w.end());
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] ^ w[i];
        while (q--) {
            int x;
            cin >> x;
            int score = 0;
            int current_weight = x;
            for (int i = 0; i < n; ++i) {
                if (current_weight >= w[i]) {
                    current_weight ^= w[i];
                    score++;
                } else {
                    break;
                }
            }
            cout << score << " ";
        }
        cout << "\n";
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