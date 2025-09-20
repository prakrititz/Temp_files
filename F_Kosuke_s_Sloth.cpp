#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve() {
    long long n, k;
    cin >> n >> k;

    long long a = 0;
    long long b = 1;
    if (k > 0) {
        b = 1 % k;
    }
    long long len = 0;
    while (len == 0 || a != 0) {
        long long c = a;
        a = b;
        b = (c + b) % k;
        len++;
    }

    cout << len * (n % mod) % mod << endl;
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