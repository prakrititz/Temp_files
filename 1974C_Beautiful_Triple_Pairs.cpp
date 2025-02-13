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

    map<pair<long long, long long>, long long> left, right, border;
    for (long long i = 1; i < n - 1; i++)
    {
        right[{a[i], a[i + 1]}]++;
        left[{a[i - 1], a[i]}]++;
        border[{a[i - 1], a[i + 1]}]++;
    }

    map<tuple<long long, long long, long long>, long long> triplet_count;
    for (long long i = 1; i < n - 1; i++)
    {
        triplet_count[{a[i - 1], a[i], a[i + 1]}]++;
    }

    long long ans = 0;
    for (auto it : left)
    {
        if (it.second >= 2)
        {
            ans += (it.second * (it.second - 1)) / 2;
        }
    }
    for (auto it : right)
    {
        if (it.second >= 2)
        {
            ans += (it.second * (it.second - 1)) / 2;
        }
    }
    for (auto it : border)
    {
        if (it.second >= 2)
        {
            ans += (it.second * (it.second - 1)) / 2;
        }
    }
    for (auto it : triplet_count)
    {
        if (it.second >= 2)
        {
            ans -= 3 * ((it.second * (it.second - 1)) / 2);
        }
    }

    cout << ans << "\n";
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
