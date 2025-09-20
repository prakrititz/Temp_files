#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];
    sort(g.begin(), g.end());
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
            ans += g[i];
    }
    if (n % 2)
    {
        long long asd = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                asd += g[i];
        }
        cout << asd << endl;
        return;
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