#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a,b;
        cin >> a >> b;
        if(a==b)
            cout << 0 << " " << 0 << '\n';
        else
        {
            long long g = abs(a-b);
            long long m = min(a%g,g-a%g);
            cout << g << " " << m << '\n';
        }
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