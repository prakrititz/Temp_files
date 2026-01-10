#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());
    vector<pair<int,int>> ans;

    if (m >= 2) {
        if (n < 2 * m) {
            cout << -1 << endl;
            return;
        }

        int K = n - 2 * m;

        for (int i = 0; i < m; i++) {
            int l = i * K / m;
            int r = (i + 1) * K / m;

            if (r - l >= 2) {
                for (int j = l; j < r - 1; j++) {
                    ans.push_back({a[j].second, a[j+1].second});
                }
            }

            if (r - l >= 1) {
                ans.push_back({a[r-1].second, a[K + i].second});
            }
        }

        for (int i = 0; i < m; i++) {
            ans.push_back({a[K + m + i].second, a[K + i].second});
        }
    }

    else if (m == 0) {
        if (n == 2) {
            cout << -1 << endl;
            return;
        }

        int largest = a[n-1].first;
        int largestId = a[n-1].second;
        int second = a[n-2].first;
        int secondId = a[n-2].second;

        int sum = 0;
        for (int i = 0; i < n-1; i++) sum += a[i].first;

        if (sum < largest) {
            cout << -1 << endl;
            return;
        }

        int need = largest - second;
        int cur = 0;
        int i = 0;

        while (i <= n-3 && cur < need) {
            ans.push_back({a[i].second, largestId});
            cur += a[i].first;
            i++;
        }
        int next = i;
        if (next <= n-3) {
            for (int i = next; i < n-3; i++) {
                ans.push_back({a[i].second, a[i+1].second});
            }
            ans.push_back({a[n-3].second, secondId});
        }

        ans.push_back({secondId, largestId});
    }
    else if (m == 1) {
        for (int i = 0; i < n-1; i++) {
            ans.push_back({a[i].second, a[i+1].second});
        }
    }

    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
