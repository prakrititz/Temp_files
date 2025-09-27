#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    vector<int> x;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] != 0)
            x.push_back(c[i]);
    }
    int N = x.size();
    int ans = INT_MIN;
    sort(x.begin(), x.end());
    for (int i = 0; i < x.size(); i++)
    {
        ans = max(ans, x[i] * (N - i));
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