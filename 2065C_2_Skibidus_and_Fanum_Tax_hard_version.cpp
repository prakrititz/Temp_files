#include <bits/stdc++.h>
using namespace std;

long long test_case_count = 0;
void solve() {
    test_case_count++;

    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(m);

    for (long long i = 0; i < n; i++)
        cin >> a[i];
    for (long long i = 0; i < m; i++)
        cin >> b[i];

    sort(b.begin(), b.end());
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    for (long long i = 0; i < a.size(); ++i) {
        long long l = 0;
        long long r = m - 1;
        long long ans = 0;
        bool found = false;
        while (r >= l) {
            long long mid = (r + l) / 2;
            if (i == 0 || b[mid] - a[i] >= a[i - 1]) {
                ans = b[mid] - a[i];
                r = mid - 1;
                found = true;
            } else {
                l = mid + 1;
            }
        }
        if ((found && a[i] >= a[i - 1]) || i == 0) {
            a[i] = min(ans, a[i]);
        } else if (found) {
            a[i] = ans;
        }
    }
    for (long long i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
