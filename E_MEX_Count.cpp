#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 5);
    vector<int> a(n);
    vector<int> pos(n + 5);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        pos[a[i]] = i;
    }
    int m = 0;
    while (cnt[m] != 0)
        m++;
    vector<int> ans(n + 5);
    for (int i = 0; i <= m; i++)
    {
        int l = min(cnt[i], n - i);
        int r = max(cnt[i], n - i);
        ans[l]++;
        ans[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
        ans[i] += ans[i - 1];
    for (int i = 0; i <= n; i++)
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