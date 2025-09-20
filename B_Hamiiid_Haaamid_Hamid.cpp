#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    if (x == 1 || x == n)
    {
        cout << 1 << endl;
        return;
    }
    x--;
    int l = x, fl = 0, r = x, cnr = 0;
    while (l >= 0 && s[l] == '.')
    {
        l--;
    }
    while (r < n && s[r] == '.')
    {
        r++;
    }
    cout << max(min(x, n - r), min(l + 1, n - x - 1)) + 1 << endl;
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