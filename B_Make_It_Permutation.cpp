#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    cout << 2 * n - 1 << endl;
    cout << 1 << " " << 1 << " " << n << endl;
    for (int i = 1; i < n; i++)
    {
        cout << i + 1 << " " << 1 << " " << i << endl;
        cout << i + 1 << " " << i + 1 << " " << n << endl;
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