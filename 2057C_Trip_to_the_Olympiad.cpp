#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    
    int k = 0;
    for (int i = 30; i >= 0; i--) {
        if ((l ^ r) & (1 << i)) {
            k = i;
            break;
        }
    }
    
    int a = l | ((1 << k) - 1);
    int b = a + 1;
    int c;
    
    if (a == l) {
        c = r;
    } else {
        c = l;
    }
    
    cout << a << " " << b << " " << c << "\n";
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