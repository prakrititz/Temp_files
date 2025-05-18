#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    int ans = pre[k];
    for (int z1 = 0; z1 <= z; z1++)
    {
        if (k - 2 * z1 < 0 || k - 2 * z1 >= n)
            continue;
        for (int i = 0; i <= k - 2 * z1; i++)
        {
            ans = max(ans, pre[k - 2 * z1] + (a[i] + a[i + 1]) * z1);
        }
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