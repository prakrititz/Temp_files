#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    int k2 = k;
    long long t1 = max((k - a + x) / x, 0ll);
    if (k < a && k < b)
    {
        cout << 0 << endl;
        return;
    }
    k -= max((k - a + x) / x, 0ll) * x;
    t1 += max((k - b + y) / y, 0ll);
    long long t2 = max((k2 - b + y) / y, 0ll);
    k2 -= max((k2 - b + y) / y, 0ll) * y;
    t2 += max((k2 - a + x) / x, 0ll);
    cout << max(t1, t2) << endl;
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