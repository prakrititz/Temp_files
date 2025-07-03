#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> c(n + 1);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i]] = i;
    }
    if (n <= 3)
    {
        cout << 1 << endl;
        return;
    }
    long long ans = 1;
    int l = min(c[0], c[1]);
    int r = max(c[0], c[1]);
    for (int i = 2; i < n; i++)
    {
        if (c[i] < r && c[i] > l)
        {
            ans *= r - l - i + 1;
            ans %= MOD;
        }
        else if (c[i] > r)
            r = c[i];
        else
            l = c[i];
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