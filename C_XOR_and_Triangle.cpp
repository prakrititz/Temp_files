#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;

    if ((x & (x - 1)) == 0 || (x & (x + 1)) == 0) {
        cout << -1 << endl;
        return;
    }

    int y = 1;
    while (y * 2 < x) {
        y *= 2;
    }

    cout << y - 1 << endl;  
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
