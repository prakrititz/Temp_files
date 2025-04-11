#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    int len = n - 2;
    for (int i = 0; i < n; i++)
    {
        if (len % a[i] == 0)
        {
            if (mp[len / a[i]])
            {
                if (a[i] == len / a[i] && mp[len / a[i]] <= 1)
                {
                    continue;
                }

                cout << a[i] << " " << len / a[i] << endl;
                return;
            }
        }
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