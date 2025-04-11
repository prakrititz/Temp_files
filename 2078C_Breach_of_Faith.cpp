#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> b[i];
    sort(b.rbegin(), b.rend());
    vector<int> a(2 * n + 1);
    int a2 = 0;
    a[0] = b[0];
    for (int i = 1; i < 2 * n; i++)
    {
        if (i % 2)
            a2 += b[i];
        else
            a2 -= b[i];
        a[i + 1] = b[i];
    }
    a[1] = a2 + b[0];
    for (int i = 0; i < 2 * n + 1; i++)
        cout << a[i] << " ";
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