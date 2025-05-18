#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (n == 2)
    {
        if (a[0] ^ a[1] == 1 && a[0] != a[1])
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            cout << "YES" << endl;
            return;
        }
    }
    bool has_liar = false;
    int sum = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        sum += a[i];
        if (a[i] == 0 && a[i + 1] == 0)
        {
            has_liar = true;
            break;
        }
    }
    sum += a[n - 1];
    if (sum == n)
        has_liar = true;
    cout << (has_liar ? "YES" : "NO") << '\n';
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