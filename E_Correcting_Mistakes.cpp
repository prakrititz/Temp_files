#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int ind1 = 0;
    int ind2 = n - 1;
    while (s[ind1] == t[ind1])
        ind1++;
    while (s[ind2] == t[ind2])
        ind2--;
    if (ind1 == ind2)
    {
        cout << 2 << endl;
        return;
    }
    int ans = 2;
    for (int i = ind1; i < ind2; i++)
    {
        if (s[i] != t[i + 1])
        {
            ans--;
            break;
        }
    }
    for (int i = ind1; i < ind2; i++)
    {
        if (t[i] != s[i + 1])
        {
            ans--;
            break;
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}