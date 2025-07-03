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
    int ans = 0;
    vector<int> c(n + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            if (a[i] == b[i])
            {
                ans = n;
                break;
            }
        }
        else if (i == n - 2)
        {
            if (a[i] == b[i] || b[i] == b[i + 1] || a[i] == a[i + 1])
            {
                ans = i + 1;
                break;
            }
        }
        else
        {
            c[a[i + 2]]++, c[b[i + 2]]++;
            if (a[i] == b[i] || b[i] == b[i + 1] || a[i] == a[i + 1] || c[b[i]] || c[a[i]])
            {
                ans = i + 1;
                break;
            }
        }
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