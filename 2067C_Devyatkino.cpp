#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long n1 = n;
    while (n1)
    {
        if (n1 % 10 == 7)
        {
            cout << 0 << endl;
            return;
        }
        n1 /= 10;
    }
    long long ans = 9;
    for (long long k = 1; k <= 9; k++)
    {
        long long num = n - k;
        long long mn = 7;
        while (num)
        {
            mn = min(mn, (7 - num % 10 + 10) % 10);
            num /= 10;
        }
        if (mn <= k)
        {
            ans = min(ans, k);
        }
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