#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    multiset<long long> r;
    multiset<long long> c;
    vector<pair<long long, long long>> a;
    for (long long i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
        r.insert(x);
        c.insert(y);
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    long long ans = LONG_LONG_MAX;
    for (long long i = 0; i < n; i++)
    {
        long long x = a[i].first;
        long long y = a[i].second;
        r.erase(r.find(x));
        c.erase(c.find(y));
        long long cost = (*r.rbegin() - *r.begin() + 1) * (*c.rbegin() - *c.begin() + 1);
        if (cost == n - 1)
        {
            cost += min(*r.rbegin() - *r.begin() + 1, *c.rbegin() - *c.begin() + 1);
        }
        ans = min(cost, ans);
        r.insert(x);
        c.insert(y);
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