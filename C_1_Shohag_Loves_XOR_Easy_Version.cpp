#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x, m;
    cin >> x >> m;
    long long count = 0;
    // x^y gives length which ever is greater, like if Y>X but  if something is a divisor of lenght Y, which can never divide X as X is of smaller length
    for (long long i = 1; i <= min(2 * x, m); i++)
    {
        long long t = x ^ i;
        if (t != 0 && (x % t == 0 || i % t == 0))
            count++;
    }
    cout << count << endl;
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