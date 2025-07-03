#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[n - 1] <= s)
    {
        cout << abs(s - a[0]) << endl;
    }
    else if (a[0] >= s)
    {
        cout << abs(s - a[n - 1]) << endl;
    }
    else
    {
        cout << abs(a[n - 1] - a[0]) + min(abs(s - a[0]), abs(s - a[n - 1])) << endl;
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