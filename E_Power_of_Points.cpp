#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (long long i = 0; i < n; i++)
    {
        long long
        
        
        
        
        x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    vector<long long> pre(n);
    vector<long long> suf(n);
    pre[0] = a[0].first;
    for (long long i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i].first;
    }
    // for (long long i = 0; i < n; i++)
    //     cout << pre[i] << " ";
    // cout << endl;
    // cout << "ewe" << endl;
    suf[n - 1] = 0;
    for (long long i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1] + a[i + 1].first;
    }
    // for (long long i = 0; i < n; i++)
    //     cout << suf[i] << " ";
    // cout << endl;
    // cout << endl;
    vector<long long> ans(n);
    for (long long i = 0; i < n; i++)
    {
        ans[a[i].second] = n + a[i].first * (2 * (i + 1) - n) - pre[i] + suf[i];
    }
    for (long long i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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