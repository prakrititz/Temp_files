#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if ((a[0] + a[n - 1]) % 2 == 0)
    {
        cout << 0 << endl;
        return;
    }
    int l = n - 1;
    int lc = 0;
    while ((a[0] + a[l]) % 2)
    {
        l--;
        lc++;
    }
    int r = 0;
    int rc = 0;
    while ((a[r] + a[n - 1]) % 2)
    {
        r++;
        rc++;
    }
    cout << min(rc, lc) << endl;
    
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