#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int o = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2)
            o++;
    }
    if (o == n || o == 0)
    {
        cout << *max_element(a.begin(), a.end()) << endl;
    }
    else
    {
        cout << accumulate(a.begin(), a.end(), 0ll) - o + 1 << endl;
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