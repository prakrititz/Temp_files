#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x = a[0];
    for (int i = 1; i < n; i++)
    {
        x ^= a[i];
    }
    if (l / 2 <= n)
    {
        int ans = a[0];
        for (int i = 1; i < l / 2; i++)
        {
            ans ^= a[i];
        }
        cout << ans << endl;
    }
    else
    {
        l = l / 2 - n;
        if (l % 2 == 0)
        {
            cout << x << endl;
        }
        else
        {
            int ans = a[0];
            for (int i = 1; i < n / 2; i++)
            {
                ans ^= a[i];
            }
            // ans ^= 0;
            cout << ans << endl;
        }
    }
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