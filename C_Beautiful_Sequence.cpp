#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp1(n + 1, 0);
    vector<int> dp2(n + 1, 0);
    vector<int> dp3(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        dp1[i + 1] = dp1[i];
        dp2[i + 1] = dp2[i];
        dp3[i + 1] = dp3[i];
        if (a[i] == 1)
            dp1[i + 1] = (dp1[i + 1] + 1) % M;
        else if (a[i] == 2)
            dp2[i + 1] = (dp2[i + 1] * 2 % M + dp1[i]) % M;
        else
            dp3[i + 1] = (dp3[i + 1] + dp2[i]) % M;
    }
    cout << dp3[n] << endl;
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