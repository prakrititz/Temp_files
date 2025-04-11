#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m;
    cin >> n >> m;

    vector<long long> x(n), r(n);
    for (long long i = 0; i < n; i++)
        cin >> x[i];
    for (long long i = 0; i < n; i++)
        cin >> r[i];

    map<long long, long long> maxY;
    for (long long i = 0; i < n; i++)
    {
        long long c = x[i], rad = r[i];

        for (long long j = c - rad; j <= c + rad; j++)
        {
            long long numy = sqrt(rad * rad - (c - j) * (c - j));
            maxY[j] = max(maxY[j], numy);
        }
    }

    long long ans = 0;
    for (auto &it : maxY)
    {
        ans += (2 * it.second + 1);
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
        solve();

    return 0;
}
