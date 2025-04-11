#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);
    if (k % 2)
    {
        ans[n - 1] = n - 1;
        for (int i = 0; i < n - 1; i++)
            ans[i] = n;
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
            ans[i] = n - 1;
        ans[n - 2] = n;
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
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