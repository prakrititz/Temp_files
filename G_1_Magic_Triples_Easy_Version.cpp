#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    map<long long, long long> mp;
    map<long long, long long> marked;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.rbegin(), a.rend());
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        if (marked[a[i]])
            continue;
        ans += mp[a[i]] * (mp[a[i]] - 1) * (mp[a[i]] - 2);
        long long sqrt_a = (long long)sqrt(a[i]);
        if (a[i] == sqrt_a * sqrt_a && a[i] != 1)
        {
            ans += mp[a[i]] * mp[sqrt_a] * mp[1];
        }
        for (long long j = 2; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                long long sqrt_j = (long long)sqrt(j);
                if (sqrt_j * sqrt_j == j)
                {
                    long long ai = a[i] / j;
                    long long aj = a[i] / sqrt_j;
                    ans += mp[a[i]] * mp[ai] * mp[aj];
                }
                long long other_divisor = a[i] / j;
                if (other_divisor != j)
                {
                    long long sqrt_other = (long long)sqrt(other_divisor);
                    if (sqrt_other * sqrt_other == other_divisor)
                    {
                        long long ai = a[i] / other_divisor;
                        long long aj = a[i] / sqrt_other;
                        ans += mp[a[i]] * mp[ai] * mp[aj];
                    }
                }
            }
        }
        marked[a[i]]++;
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