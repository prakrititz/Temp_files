#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    string a, b;
    cin >> n;
    cin >> a;
    cin >> m;
    cin >> b;
    string c;
    cin >> c;
    deque<char> s;
    for (int i = 0; i < a.size(); i++)
        s.push_back(a[i]);
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] == 'V')
            s.push_front(b[i]);
        else
        {
            s.push_back(b[i]);
        }
    }
    for (auto it : s)
    {
        cout << it;
    }
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