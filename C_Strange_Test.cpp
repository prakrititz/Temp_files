#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b;
    cin >> a >> b;
    long long ans = LLONG_MAX;
    for (long long a1 = a; a1 <= b - 1; a1++)
    {
        long long val = 0;
        for (long long i = 23; i >= 0; i--)
        {
            long long x = 0;
            long long bit = 1LL << i;
            if (!(bit & a1) && (bit & b))
            {
                x = 1;
            }
            if ((bit & a1) && (bit & b))
            {
                x = 1;
            }
            if ((bit & a1) && !(bit & b))
            {
                x = 1;
                break;
            }
            if (x)
            {
                val += 1LL << i;
            }
        }
        ans = min(ans, (a1 - a) + (a1 | val) - b + 1);
    }
    ans = min(ans, b - a);
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