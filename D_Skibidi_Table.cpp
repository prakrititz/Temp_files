#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long q;
    cin >> q;
    long long t = 1;
    for (long long i = 0; i < n; i++)
        t *= 2;
    while (q--)
    {
        char s;
        cin >> s >> s;
        if (s == '>')
        {
            long long size = t;
            long long x, y;
            cin >> x >> y;
            long long ans = 1;
            while (size > 1)
            {
                long long m = size / 2;
                if (x > m && y > m)
                {
                    x -= m;
                    y -= m;
                    ans += (m * m);
                }
                else if (x > m)
                {
                    x -= m;
                    ans += 2 * m * m;
                }
                else if (y > m)
                {
                    y -= m;
                    ans += 3 * m * m;
                }
                size = size / 2;
            }
            cout << ans << endl;
        }
        else
        {
            long long v;
            cin >> v;
            v--;
            long long size = t;
            long long x = 1, y = 1;
            while (size % 2 == 0)
            {
                size /= 2;
                if (v / (size * size) == 1)
                {
                    x += size;
                    y += size;
                    v -= size * size;
                }
                else if (v / (size * size) == 2)
                {
                    x += size;
                    v -= size * size * 2;
                }
                else if (v / (size * size) == 3)
                {
                    y += size;
                    v -= size * size * 3;
                }
            }
            cout << x << " " << y << endl;
        }
    }
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