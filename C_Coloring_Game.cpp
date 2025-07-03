#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0;
    for (long long i = 0; i < n - 2; i++)
    {
        for (long long j = i + 1; j < n - 1; j++)
        {
            auto it = lower_bound(a.begin(), a.end(), a[i] + a[j]);
            long long end = it - (a.begin() + j + 1);
            if (end == 0)
                continue;
            it = upper_bound(a.begin() + j + 1, a.begin() + j + end + 1, a[n - 1] - a[i] - a[j]);
            ans += (a.begin() + j + end + 1) - it;
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