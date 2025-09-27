#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % 3)
    {
        cout << 0 << " " << 0 << endl;
    }
    else
    {
        cout << 1 << " " << n - 1 << endl;
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