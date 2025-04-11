#include <bits/stdc++.h>

using namespace std;
void solve()
{
    long long k;
    // for (int parameter = 1; parameter <= 100000; parameter++)
    // {
    // k = parameter;
    cin >> k;
    long long n = 1;
    while ((n * (n - 1)) / 2 <= k)
    {
        n++;
    }
    n--;
    // cout << n << endl;
    long long pairs_formed = (n * (n - 1)) / 2;
    // cout << pairs_formed << endl;
    long long remaining_pairs = k - pairs_formed;
    int t = 1;
    while ((t * (t - 1)) / 2 <= remaining_pairs)
    {
        t++;
    }
    t--;
    long long pairs_formed2 = (t * (t - 1)) / 2;
    // cout << pairs_formed2 << endl;
    long long rem2 = remaining_pairs - pairs_formed2;
    int total = rem2 + t + n;
    if (total > 500)
    {
        // cout << total << endl;
        total -= 4;
        cout << total << endl;
        for (long long i = 0; i < n; i++)
        {
            cout << "0 " << i << endl;
        }
        for (long long i = 0; i < t; i++)
        {
            cout << "-1 " << -i << endl;
        }
        for (long long i = 1; i <= rem2 - 6; i++)
        {
            cout << i << " " << i << endl;
        }
        cout << "-2" << " " << "0" << endl;
        cout << "-3" << " " << "0" << endl;
    }
    else
    {
        cout << total << endl;
        for (long long i = 1; i <= n; i++)
        {
            cout << "0 " << i << endl;
        }
        for (long long i = 1; i <= t; i++)
        {
            cout << "-1 " << -i << endl;
        }
        for (long long i = 1; i <= rem2; i++)
        {
            cout << i << " " << i << endl;
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
