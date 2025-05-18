#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x;
    cin >> n >> x;
    if (n == x)
    {
        cout << n << endl;
        return;
    }
    else if (x > n)
    {
        cout << -1 << endl;
        return;
    }
    else if (x == 0)
    {
        if (n == 0)
        {
            cout << 0 << endl;
            return;
        }
        long long msb = 1LL << (63 - __builtin_clzll(n));
        msb *= 2;
        cout << msb << endl;
    }
    else
    {
        if (x & (x - 1) != 0 || x & n != x)
        {
            cout << -1 << endl;
            return;
        }
        long long ans = n;
        long long limit = LLONG_MAX;
        for (int i = 0; i < 64; i++)
        {
            long long bit = 1ll << i;
            if ((x & bit) && !(n & bit))
            {
                cout << -1 << endl;
                return;
            }
            else if ((x & bit) && (n & bit))
            {
                limit = min(limit, ((n >> i) << i) + bit - 1);
            }
            else if (!(x & bit) && (n & bit))
            {
                ans = max(ans, ((n >> i) << i) + bit);
            }
        }
        if (limit < ans)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
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