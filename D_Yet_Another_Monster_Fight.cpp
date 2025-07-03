#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pre(n);
    vector<int> suff(n);
    for (int i = 0; i < n; i++)
    {
        pre[i] = a[i] + (n - i - 1);
        suff[i] = a[i] + i;
    }
    for (int i = 1; i < n; i++)
    {
        pre[i] = max(pre[i], pre[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        suff[i] = max(suff[i], suff[i + 1]);
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        int cur = a[i];
        if (i > 0)
            cur = max(cur, pre[i - 1]);
        if (i + 1 < n)
            cur = max(cur, suff[i + 1]);
        ans = min(ans, cur);
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}