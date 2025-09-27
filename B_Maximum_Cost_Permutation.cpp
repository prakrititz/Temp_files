#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            s.erase(a[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            a[i] = *s.begin();
            s.erase(*s.begin());
        }
    }
    int i = 0;
    int j = n - 1;
    int c = 1;
    while (i < n && a[i] == c)
    {
        i++;
        c++;
    }
    c = n;
    while (j >= 0 && a[j] == c)
    {
        j--;
        c--;
    }
    cout << max(0, j - i + 1) << endl;
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