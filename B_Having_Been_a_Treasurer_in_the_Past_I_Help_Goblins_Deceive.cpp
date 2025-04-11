#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long cntM = 0;
    long long cntU = 0;

    for (char c : s)
    {
        if (c == '-')
        {
            cntM++;
        }
        else if (c == '_')
        {
            cntU++;
        }
    }
    if (cntM < 2 || cntU == 0)
    {
        cout << 0 << endl;
        return;
    }
    long long x = cntM / 2;
    long long result = x * cntU * (cntM - x);
    cout << result << endl;
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