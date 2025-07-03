#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, s;
    cin >> n >> s;
    vector<vector<long long>> a(n);
    long long cnt = 0;
    for (long long i = 0; i < n; i++)
    {
        long long x, y, z, w;
        cin >> x >> y >> z >> w;
        a[i] = {x, y, z, w};
        if (z + w == s && x * y == -1)
        {
            cnt++;
        }
        else if (z == w && x == y)
            cnt++;
    }
    cout << cnt << endl;
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