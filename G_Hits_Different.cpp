#include <bits/stdc++.h>
using namespace std;
long long sum2(long long l, long long r)
{
    l--;
    return (r * (2 * r + 1) * (r + 1)) / 6 - (l * (2 * l + 1) * (l + 1)) / 6;
}
void solve()
{
    long long n;
    cin >> n;
    long long x = 1;
    while (x * (x + 1) / 2 < n)
        x++;
    // cout << x << endl;
    long long y = n - (x * (x - 1)) / 2;
    // cout << y << endl;
    long long ans = 0;
    for (long long i = 1; i <= x; i++)
    {
        long long l = max(1ll, y - (x - i));
        long long r = min(i, y);
        ans += sum2(i * (i - 1) / 2 + l, i * (i - 1) / 2 + r);
    }
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