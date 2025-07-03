#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string l, r;
    cin >> l >> r;
    int n = l.size();
    int ans = 0;
    int i = 0;
    while (i < n && l[i] == r[i])
    {
        i++;
        ans += 2;
    }
    if (r[i] - l[i] == 1)
    {
        i++;
        ans++;
        while (i < n && ((l[i] == '9' && r[i] == '0')))
        {
            i++;
            ans += 1;
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