#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(b.rbegin(), b.rend());
    int i = 0;
    int j = 0;
    vector<int> c;
    while (i < n && j < m)
    {
        if (a[i] > b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }
    while (i < n)
    {
        c.push_back(a[i]);
        i++;
    }
    while (j < m)

    {
        c.push_back(b[j]);
        j++;
    }
    for (auto it : c)
        cout << it << " ";
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