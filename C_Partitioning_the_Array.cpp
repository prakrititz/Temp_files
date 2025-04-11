#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> factors;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            factors.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < factors.size(); i++)
    {
        int count = 0;
        int k = factors[i];
        int g = 0;
        for (int j = 0; j < n - k; j++)
        {
            g = gcd(g, abs(a[j + k] - a[j]));
        }
        if (g != 1)
            count++;
        ans += count;
    }
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