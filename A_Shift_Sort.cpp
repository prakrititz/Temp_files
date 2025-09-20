#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (auto c : s)
        a.push_back(c - '0');
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            cnt++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i < cnt && s[i] == '1')
            ans++;
        else if (i >= cnt && s[i] == '0')
            ans++;
    }
    cout << ans / 2 << endl;
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