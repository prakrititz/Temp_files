#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            cout << "? " << (mid - l + 1);
            for (int i = l; i <= mid; ++i) {
                cout << " " << i + 1;
            }
            cout << endl;
            cout.flush();

            int total;
            cin >> total;
            int expected_sum = 0;
            for (int i = l; i <= mid; ++i) {
                expected_sum += a[i];
            }

            if (total > expected_sum) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << "! " << l + 1 << endl;
        cout.flush();
    }
    return 0;
}
