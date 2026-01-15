#include<bits/stdc++.h>
using namespace std;
#define int long long 

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    if (k > n) {
        cout << -1 << endl;
        return;
    }

    long long lo = n;
    long long hi = n;
    int t = 0;

    while (true) {
        if (lo == k || hi == k) {
            cout << t << endl;
            return;
        }

        if (hi < k) {
            cout << -1 << endl;
            return;
        }

        lo = lo / 2;
        hi = (hi + 1) / 2;
        t++;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
