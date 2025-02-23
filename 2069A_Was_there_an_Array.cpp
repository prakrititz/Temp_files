#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    n-=2;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 2; i++)
    {
        if (a[i] == 1 && a[i + 1] == 0 && a[i + 2] == 1)
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