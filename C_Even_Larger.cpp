#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n % 2 == 0)
    {
        n++;
        a.push_back(0);
    }

    long long ans = 0;
    for (int i = 1; i < n; i += 2)
    {
        if (a[i + 1] + a[i - 1] > a[i])
        {
            int t = min(a[i + 1] + a[i - 1] - a[i], a[i + 1]);
            a[i + 1] -= t;
            ans += t;
        }
        if (a[i - 1] > a[i])
        {
            ans += a[i - 1] - a[i];
        }
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