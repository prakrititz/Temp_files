#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    if (abs(n - m) > k || max(n, m) < k) {
        cout << -1 << endl;
        return;
    }
    
    int t = 0;
    if (n < m) {
        swap(n, m);
        t = 1;
    }
    
    string s;
    for (int i = 0; i < k && n; i++) {
        s += '0' ^ t;
        n--;
    }
    while (n > 0 && m > 0) {
        if (m > 0) {
            s += '1' ^ t;
            m--;
        }
        if (n > 0) {
            s += '0' ^ t;
            n--;
        }
    }
    while (m > 0) {
        s += '1' ^ t;
        m--;
    }
    while (n > 0) {
        s += '0' ^ t;
        n--;
    }
    
    cout << s << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}