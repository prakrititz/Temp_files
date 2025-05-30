#include <bits/stdc++.h>
using namespace std;
int func(int val, int k)
{
    vector<int> div;
    for (int i = 1; i * i <= val; i++)
    {
        if (val % i == 0)
        {
            div.push_back(i);
            if (i * i != val)
                div.push_back(val / i);
        }
    }
    sort(div.begin(), div.end());
    vector<int> dp(div.size(), 100);
    dp[0] = 0;
    for (int i = 0; i < div.size(); i++)
    {
        if (dp[i] >= 100)
            continue;
        for (int d : div)
        {
            if (d > k)
                break;
            if (1ll * div[i] * d > val)
                break;
            int prod = div[i] * d;
            int j = lower_bound(div.begin(), div.end(), prod) - div.begin();
            if (j < div.size() && div[j] == prod) 
                dp[j] = min(dp[i] + 1, dp[j]);
        }
    }
    int t = lower_bound(div.begin(), div.end(), val) - div.begin();
    return dp[t];
}
void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    int remx = x;
    int remy = y;
    if (x == y)
    {
        cout << 0 << endl;
        return;
    }
    remx /= gcd(x, y);
    remy /= gcd(x, y);
    int ans = func(remx, k) + func(remy, k);
    if (ans >= 100)
        cout << -1 << endl;
    else
        cout << ans << endl;
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