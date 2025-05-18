#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;

    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long s = 0;
    long long ans = 0;
    long long mx = 0;
    long long first = 1;

    map<long long, long long> cnt;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (first)
            {
                first = 0;
                ans += cnt[0];
            }
            else
            {
                ans += mx;
            }
            mx = 0;
            cnt.clear();
        }
        s += a[i];
        cnt[s]++;
        mx = max(mx, cnt[s]);
    }
    if (first)
    {
        first = 0;
        ans += cnt[0];
    }
    else
    {
        ans += mx;
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