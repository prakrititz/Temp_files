#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    map<int, int> ma;
    vector<int> b(n);
    map<int, int> mb;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        mb[b[i]]++;
    }
    // for (auto x : mb)
    //     cout << x.first << " ";
    // cout << endl;
    for (auto x : mb)
    {
        int s = min(ma[x.first], x.second);
        ma[x.first] -= s;
        mb[x.first] -= s;
    }
    // for (auto x : mb)
    //     cout << x.first << " ";
    // cout << endl;
    for (auto x : mb)
    {
        if (x.first > 9)
        {
            int num = log10(x.first) + 1;
            ans += x.second;
            mb[num] += x.second;
            mb[x.first] = 0;
        }
    }

    for (auto x : ma)
    {
        if (x.first > 9)
        {
            int num = log10(x.first) + 1;
            ans += x.second;
            ma[num] += x.second;
            ma[x.first] = 0;
        }
    }
    for (auto x : mb)
    {
        if (x.second != 0)
        {
            int s = min(ma[x.first], x.second);
            ma[x.first] -= s;
            mb[x.first] -= s;
        }
    }
    for (auto x : mb)
    {
        if (x.first != 1)
            ans += x.second;
    }
    for (auto x : ma)
    {
        if (x.first != 1)
            ans += x.second;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}