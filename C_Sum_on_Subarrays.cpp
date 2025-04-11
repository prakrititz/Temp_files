#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    k = (n * (n + 1)) / 2 - k;
    int t = 0;
    while (1LL * t * (t + 1) / 2 <= k)
    {
        t++;
    }
    t--;
    if (k == 0)
    {
        for (int i = 0; i < n; i++)
            cout << 1000 << " ";
        cout << endl;
        return;
    }
    // cout << t << endl;
    vector<int>
        ans(n, 1000);
    for (int i = 0; i < t; i++)
    {
        ans[i] = -2;
    }
    int rem = max(0, k - (t * (t + 1)) / 2);
    if (rem != 0)
    {
        if (t < n)
        {
            ans[t] = (t - rem) * 2 + 1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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
