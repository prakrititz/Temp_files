#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if (count(s.begin(), s.end(), '0') == 0)
    {
        cout << 1LL * n * n << endl;
        return;
    }
    if (s.size() != 1)
        s += s;
    int cnt = 0;
    int maxi = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            cnt++;
        else
            cnt = 0;
        maxi = max(cnt, maxi);
    }
    if (maxi <= 1)
    {
        cout << maxi << endl;
    }
    else
    {
        n = maxi;
        cout << 1ll * ((n + 2) / 2) * ((n + 1) / 2) << endl;
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