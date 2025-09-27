#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = i + 1;

    bool ok = true;
    int i = 0;
    while (i < n)
    {
        if (s[i] == '0')
        {
            int j = i;
            while (j < n && s[j] == '0')
                j++;
            int len = j - i;

            if (len == 1)
            {
                ok = false;
                break;
            }
            reverse(ans.begin() + i, ans.begin() + j);
            i = j;
        }
        else
        {
            i++;
        }
    }

    if (!ok)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
