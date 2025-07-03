#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool flag = false;
    if (a[1] < a[0])
    {
        reverse(a.begin(), a.end());
    }
    if (a[1] < a[0])
    {
        cout << "NO" << endl;

        return;
    }

    int x = a[1] - a[0];
    int y = (a[0] - x) / (n + 1);
    if (y < 0)
    {
        cout << "NO" << endl;

        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != y * (n + 1) + x * (i + 1))
        {
            cout << "NO" << endl;

            return;
        }
    }
    cout << "YES" << endl;
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