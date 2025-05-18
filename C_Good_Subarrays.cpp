#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    long long sum = 0;
    map<long long, long long> mp;
    mp[0] = 1;
    for (long long i = 0; i < n; i++)
    {
        long long x = s[i] - '1';
        sum += x;
        mp[sum]++;
    }
    for (auto x : mp)
    {
        ans += (x.second * (x.second - 1)) / 2;
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