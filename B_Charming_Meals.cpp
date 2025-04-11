#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<vector<int>> diff(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            diff[i][j] = abs(a[i] - b[j]);
        }
    }
    int ans = INT_MIN;
    for (int t = 0; t < n; t++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(diff[i][(i + t) % n], mini);
        }
        ans = max(mini, ans);
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