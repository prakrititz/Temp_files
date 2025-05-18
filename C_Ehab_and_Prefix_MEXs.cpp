#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n, -1);
    map<int, int> mp;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            b[i] = a[i - 1];
            mp[b[i]]++;
        }
    }
    mp[a[n-1]]++;
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        while (mp[val])
            val++;
        if (b[i] == -1)
        {
            b[i] = val;
            mp[b[i]]++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}