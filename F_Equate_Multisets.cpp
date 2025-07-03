#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    multiset<int> ms;
    multiset<int> bs;
    for (int i = 0; i < n; i++)
    {
        while (a[i] % 2 == 0)
        {
            a[i] /= 2;
        }
        ms.insert(a[i]);
        bs.insert(b[i]);
    }
    bool flag = true;
    while (!bs.empty())
    {
        int x = *bs.rbegin();
        if (ms.count(x))
        {
            ms.erase(ms.find(x));
            bs.erase(bs.find(x));
        }
        else
        {
            if (x == 1)
            {
                break;
            }
            bs.erase(bs.find(x));
            bs.insert(x / 2);
        }
    }
    if (bs.empty())
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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