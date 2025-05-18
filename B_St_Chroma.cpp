#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = i;
    }
    if (x == n)
    {
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
        return;
    }
    swap(ans[n - 1], ans[x]);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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