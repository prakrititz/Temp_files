#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int first = -1;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (first== -1 && s[i] == '1')
        {
            first = i;
        }
        if (s[i] == '0')
        {
            last = i;
        }
    }
    string ans = "";
    if (first< last && last != -1 && first != -1)
    {
        for (int i = 0; i < first; i++)
        {
            ans += s[i];
        }
        ans += '0';
        for (int i = last + 1; i < n; i++)
        {
            ans += s[i];
        }
        cout << ans << endl;
    }
    else
    {
        cout << s << endl;
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