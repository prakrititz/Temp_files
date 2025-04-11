#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            int j = (2 * i - 1) % n;
            if (j == 0)
                j = n;
            p[j] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << p[i] << (i < n ? " " : "\n");
        }
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