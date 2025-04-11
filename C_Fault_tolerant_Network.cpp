#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    for (long long i = 0; i < n; i++)
        cin >> b[i];
    long long left1 = LONG_LONG_MAX;
    long long left2 = LONG_LONG_MAX;
    long long right1 = LONG_LONG_MAX;
    long long right2 = LONG_LONG_MAX;
    long long ans = min(abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]),
                        abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
    for (int i = 0; i < n; i++)
    {
        left1 = min(abs(a[0] - b[i]), left1);
        left2 = min(abs(b[0] - a[i]), left2);
        right1 = min(abs(a[n - 1] - b[i]), right1);
        right2 = min(abs(b[n - 1] - a[i]), right2);
    }
    long long var1 = abs(a[0] - b[0]) + right1 + right2;
    long long var2 = abs(a[n - 1] - b[n - 1]) + left1 + left2;
    long long var3 = abs(a[0] - b[n - 1]) + left2 + right1;
    long long var4 = abs(a[n - 1] - b[0]) + left1 + right2;
    long long var5 = left1 + right1 + right2 + left2;
    ans = min(min(min(min(min(var1, var2), var3), var4), ans), var5);
    cout << ans << endl;
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