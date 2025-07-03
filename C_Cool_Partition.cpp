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
    set<int> cur;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
        cur.insert(a[i]);
        if (s.size() == cur.size())
        {
            t++;
            s.clear();
        }
    }
    cout << t << endl;
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