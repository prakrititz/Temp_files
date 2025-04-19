#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
void solve()
{
    string s;
    cin >> s;
    vector<int> a;
    for (char c : s)
    {
        if (c == '0')
            a.push_back(-1);
        else
            a.push_back(1);
    }

    map<int, long long> mp;
    long long sum = 0, ans = 0;
    int n = a.size();
    mp[0] = 1;

    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
        ans = (ans + ((1LL * (n - i) * mp[sum]) % MOD)) % MOD;
        mp[sum] = (mp[sum] + i + 2) % MOD;
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