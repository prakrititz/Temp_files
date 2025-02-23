#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    long long ans = 0, max0 = 0, max1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            max0++;
            max1 = 0;
            ans += max0;
        }
        else if (s[i] == '1')
        {
            max1++;
            max0 = 0;
            ans += max1;
        }
        else
        {
            max0++;
            max1++;
            ans += max(max0, max1);
        }
        swap(max0, max1);
    }

    cout << ans << "\n";
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