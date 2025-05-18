#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    long long row_min = min(a, n - a + 1);
    long long col_min = min(b, m - b + 1);
    long long cost_row_cut = ceil(log2(m)) + ceil(log2(row_min));
    long long cost_col_cut = ceil(log2(n)) + ceil(log2(col_min));
    long long ans = 1 + min(cost_row_cut, cost_col_cut);
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