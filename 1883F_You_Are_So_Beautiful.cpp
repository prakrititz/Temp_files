#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> lastP;
    for (int i = 0; i < n; i++) {
        lastP[a[i]] = i;
    }

    vector<int> indP(n, 0);
    for (int i = 0; i < n; i++) {
        if (lastP[a[i]] == i) {
            indP[i] = 1;
        }
    }

    long long cur = 0;
    vector<long long> suf(n);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = cur + indP[i];
        cur = suf[i];
    }

    long long ans = 0;
    map<int, int> marked;
    for (int i = 0; i < n; i++) {
        if (marked[a[i]] != 1) {
            ans += suf[i];
            marked[a[i]] = 1;
        }
    }

    cout << ans << endl;
    return;
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
