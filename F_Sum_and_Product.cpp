#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    map<long double, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    long long q;
    cin >> q;
    vector<long long> ans;
    while (q--)
    {
        long long x;
        long long y;
        cin >> x >> y;
        long long disc = (long long)x * x - 4 * y;
        if (disc < 0)
        {
            ans.push_back(0);
        }
        else
        {
            long double de = sqrt((long double)disc);
            long double x1 = ((long double)x + de) / 2.0;
            long double x2 = ((long double)x - de) / 2.0;
            if (x1 != x2)
            {
                ans.push_back(mp[x1] * mp[x2]);
            }
            else
            {
                ans.push_back((mp[x1] * (mp[x1] - 1)) / 2);
            }
        }
    }
    for (long long i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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