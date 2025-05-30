#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i == 0)
        {
            a.push_back(x);
            continue;
        }
        if (x != a.back())
        {
            a.push_back(x);
        }
    }
    n = a.size();
    vector<int> t(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1] + 1)
        {
            t[i] = 0;
            i++;
        }
    }

    int ans = accumulate(t.begin(), t.end(), 0);
    cout << ans << endl;
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