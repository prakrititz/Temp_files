#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x, m;
    cin >> x >> m;
    long long count = 0;
    if (m <= 2 * x)
    {
        for (long long i = 1; i <= m; i++)
        {
            if ((x ^ i) % i == 0 || (x ^ i) % x == 0)
            {
                count++;
            }
        }
        cout << count << endl;
        return;
    }
    for (long long i = 1; i < 2 * x && i <= m; i++)
    {
        if ((x ^ i) < 2 * x && (x ^ i) % x == 0 || (x ^ i) % i == 0)
            count++;
    }
    if (m - x >= 2 * x)
    {
        count += (m - x) / x;
        count -= (2 * x - 1) / x;
    }
    for (long long z = max(2LL * x, m - x + 1); z <= m + x; z++)
    {
        if (z % x)
            continue;
        long long y = z ^ x;
        if (y >= 1 && y <= m)
            count++;
    }

    cout << count << endl;
}

main()
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