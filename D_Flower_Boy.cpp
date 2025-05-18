#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<int> pre(m + 1, n + 1), suf(m + 1, -1);
    pre[0] = 0;
    for (int i = 0, j = 0; i < m; i++)
    {
        while (j < n && a[j] < b[i])
        {
            j++;
        }
        if (j == n)
        {
            break;
        }
        pre[i + 1] = ++j;
    }
    suf[m] = n;
    for (int i = m - 1, j = n - 1; i >= 0; i--)
    {
        while (j >= 0 && a[j] < b[i])
        {
            j--;
        }
        if (j < 0)
        {
            break;
        }
        suf[i] = j--;
    }

    if (pre[m] <= n)
    {
        cout << 0 << endl;
        return;
    }
     
    int ans = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        if (pre[i] <= suf[i + 1])
        {
            ans = min(ans, b[i]);
        }
    }
    if (ans == INT_MAX)
    {
        ans = -1;
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