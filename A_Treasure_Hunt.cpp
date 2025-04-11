#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x, y, a;
    cin >> x >> y >> a;

    long long depth = 2 * a + 1;
    long long pair_dig = 2 * (x + y);
    long long complete_pairs = (depth - 1) / pair_dig;
    long long dug_after_pairs = complete_pairs * pair_dig;

    if (dug_after_pairs + 2 * x >= depth)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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