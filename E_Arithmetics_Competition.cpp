#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    vector<long long> prea(n + 1, 0), preb(m + 1, 0);
    for (int i = 1; i <= n; i++)
        prea[i] = prea[i - 1] + a[i - 1];
    for (int i = 1; i <= m; i++)
        preb[i] = preb[i - 1] + b[i - 1];

    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int L = max(0, z - y);
        int R = min(x, z);
        int lo = L, hi = R - 1, pos = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (a[mid] < b[z - mid - 1])
            {
                pos = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        int k;
        if (pos == -1)
            k = R;
        else
            k = pos;
        cout << (prea[k] + preb[z - k]) << endl;
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