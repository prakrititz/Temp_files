#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return s[i] < s[n - i - 1];
        }
    }
    return false;
}

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    if (check(s))
    {
        cout << "YES" << endl;
        return;
    }

    if (k == 0)
    {
        cout << "NO" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(s[i], s[j]);
            if (check(s))
            {
                cout << "YES" << endl;
                return;
            }
            swap(s[i], s[j]);
        }
    }

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
