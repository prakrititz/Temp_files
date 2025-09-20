#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    vector<int> f(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            f[i] = f[i + 1];
        }
        if (s[i] == '1') {
            f[i]++;
        } else {
            f[i]--;
        }
    }
    f.erase(f.begin());
    sort(f.begin(), f.end(), greater());
    
    long long sum = 0;
    for (int i = 1; i < n; i++) {
        sum += f[i - 1];
        if (sum >= k) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}