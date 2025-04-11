#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long odd = 0, even = 0;
    vector<long long> a(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2)
            odd++;
        else
            even++;
    }

    if (even != 0 && odd != 0)
    {
        cout << 2 << endl;
        return;
    }

    long long k = 2;
    while (true)
    {
        map<long long, long long> mp;
        for (long long i = 0; i < n; i++)
        {
            long long modValue = a[i] % k;
            mp[modValue]++;
        }

        if (mp.size() == 2)
        {
            cout << k << endl;
            return;
        }

        k *= 2;
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
