#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long l, r, g;
    cin >> l >> r >> g;
    bool f = false;
    long long l1, r1;
    long long L = (l + g - 1) / g;
    long long R = r / g;
    for (long long d = R - L; d >= 0; d--)
    {
        for (long long a = L; a + d <= R; a++)
        {
            long long b = a + d;
            if (gcd(a, b) == 1)
            {
                cout << a * g << " " << b * g << "\n";
                return;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
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