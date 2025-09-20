#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    char c1, c2;
    long long x, y;
    long long a = 1, b = 1;
    long long extra = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> c1 >> x >> c2 >> y;
        if (c1 == 'x' && c2 == 'x')
        {
            if (x == y)
            {
                extra += (extra + a + b) * (x - 1);
            }
            else if (x > y)
            {
                a += extra;
                extra = a * (x - 1) + b * (y - 1);
            }
            else
            {
                b += extra;
                extra = a * (x - 1) + b * (y - 1);
            }
        }
        else if (c1 == 'x')
        {
            a += extra;
            extra = a * (x - 1) + y;
        }
        else if (c2 == 'x')
        {
            b += extra;
            extra = b * (y - 1) + x;
        }
        else
        {
            extra += x + y;
        }
    }
    cout << a + b + extra << endl;
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