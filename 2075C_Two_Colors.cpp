#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    vector<int> b(m), c(m);
    for (int i = 0; i < m; i++)
    {
        b[i] = min(a[i], n - 1);
        c[i] = max(n - a[i], 1);
    }
    vector<int> s = c;
    sort(s.begin(), s.end());

    vector<long long> pre(m + 1, 0);
    for (int i = 0; i < m; i++)
    {
        pre[i + 1] = pre[i] + s[i];
    }

    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        int pos = upper_bound(s.begin(), s.end(), b[i]) - s.begin();
        long long sumL = pre[pos];
        ans += (long long)pos * b[i] - sumL + pos;
        if (c[i] <= b[i])
        {
            ans -= (b[i] - c[i] + 1);
        }
    }
    cout << ans << '\n';
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