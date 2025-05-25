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
    vector<int> suf(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = max(pre[i - 1], a[i]);
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = min(a[i], suf[i + 1]);
    vector<int> ans(n);
    ans[n - 1] = pre[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (pre[i] > suf[i + 1])
            ans[i] = ans[i + 1];
        else
            ans[i] = pre[i];
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