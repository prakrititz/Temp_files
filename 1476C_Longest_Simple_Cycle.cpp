#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> c(n);
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++)
        cin >> c[i];
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    for (long long i = 0; i < n; i++)
        cin >> b[i];
    vector<long long> maxi(n);
    maxi[0] = 0;
    maxi[1] = c[1] + abs(b[1] - a[1]) + 1ll;
    for (long long i = 2; i < n; i++)
    {
        if (a[i] == b[i])
        {
            maxi[i] = c[i] + 1;
        }
        else
        {
            long long overlap = abs(b[i] - a[i]);
            maxi[i] = max(maxi[i - 1] + c[i] + 1ll - overlap, c[i] + 1ll + abs(b[i] - a[i]));
        }
    }
    long long ans = 0;
    for (auto val : maxi)
    {
        ans = max(val, ans);
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