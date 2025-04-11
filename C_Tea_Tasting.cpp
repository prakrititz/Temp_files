#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    for (long long i = 0; i < n; i++)
        cin >> b[i];
    vector<long long> pre(n);
    pre[0] = b[0];
    for (long long i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + b[i];
    }

    vector<long long> ans(n, 0);
    vector<long long> cnt(n, 0);
    ans[0] = min(a[0], b[0]);
    for (long long i = 0; i < n; i++)
    {

        long long sub = 0;
        if (i != 0)
            sub = pre[i - 1];
        long long j = lower_bound(pre.begin() + i, pre.end(), a[i] + sub) - pre.begin();
        if (j > i)
        {
            cnt[i]++;
            if (j < n)
            {
                cnt[j]--;
            }
        }
        // for (long long i = 0; i < n; i++)
        //     cout << cnt[i] << " ";
        // cout << endl;
        if (j < n && j > 0)
        {
            long long subs = 0;
            if (i != 0)
                subs = pre[i - 1];
            ans[j] += a[i] - (pre[j - 1] - subs);
        }
        // for (long long i = 0; i < n; i++)
        //     cout << ans[i] << " ";
        // cout << endl;
    }
    for (long long i = 1; i < n; i++)
    {
        cnt[i] = cnt[i - 1] + cnt[i];
    }

    for (long long i = 1; i < n; i++)
    {
        ans[i] += cnt[i] * b[i];
    }
    for (long long i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return;
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