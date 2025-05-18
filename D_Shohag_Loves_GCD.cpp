#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> s(m);
    for (int i = 0; i < m; i++)
        cin >> s[i];
    sort(s.rbegin(), s.rend());
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + i; j <= n; j += i)
        {
            a[j] = max(a[j], a[i] + 1);
        }
    }

    if (*max_element(a.begin(), a.end()) >= m)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
            cout << s[a[i]] << " ";
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