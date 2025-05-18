#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    bool flag = true;
    int l, r;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            l = r = h[i];
        }
        else
        {
            // PREV MIN -K+1, [I]
            l = max(l - k + 1, h[i]);
            r = min(r + k - 1, h[i] + k - 1);
        }
        if (l > r)
        {
            flag = false;
        }
        if (i == n - 1 && l != h[i])
        {
            flag = false;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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