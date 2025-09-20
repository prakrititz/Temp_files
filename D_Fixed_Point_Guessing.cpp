#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int l = 1, r = n;

    while (l <= r)
    {
        int m = (l + r) / 2;

        cout << "? " << l << " " << m << endl;
        cout.flush(); 

        int cnt = 0;
        for (int i = l; i <= m; i++)
        {
            int c;
            cin >> c;
            if (c >= l && c <= m)
                cnt++;
        }

        if (cnt % 2 == 0)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << "! " << l << endl;
    cout.flush();
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
