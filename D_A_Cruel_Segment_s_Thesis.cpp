#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> l(n), r(n);
    ll base = 0, sumR = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        base += r[i] - l[i];
        sumR += r[i];
    }

    vector<ll> s(n);
    for (int i = 0; i < n; i++) s[i] = l[i] + r[i];

    ll add = 0;
    if (n % 2 == 0) {
        int m = n / 2;
        nth_element(s.begin(), s.begin() + m, s.end());
        ll sm = 0;
        for (int i = 0; i < m; i++) sm += s[i];
        add = sumR - sm;
    } else {
        int m = (n - 1) / 2;
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return s[a] < s[b];
        });

        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + s[idx[i]];

        ll best = -1e18;
        for (int i = 0; i < n; i++) {
            ll sm;
            if (i < m) {
                sm = pref[m + 1] - s[idx[i]];
            } else {
                sm = pref[m];
            }
            best = max(best, sumR - sm);
        }
        add = best;
    }

    cout << base + add << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
