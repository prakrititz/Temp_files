#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b;
    cin >> a >> b;

    long long ans = -1;

    vector<long long> div;
    div.push_back(1);
    if (b % 2 == 0)
        div.push_back(2);
    div.push_back(b);
    if (b % 2 == 0)
        div.push_back(b / 2);

    for (long long k : div)
    {
        if (b % k != 0)
            continue;
        long long a1 = (long long)a * k;
        long long b1 = b / k;
        long long sum = (long long)(a1 + b1);
        if (sum % 2 == 0)
            ans = max(ans, sum);
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
        solve();
    return 0;
}
