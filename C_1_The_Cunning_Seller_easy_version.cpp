#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long ans = 0;
        int pos = 0;
        while (n > 0)
        {
            int d = n % 3;
            for (int k = 0; k < d; k++)
            {
                long long p = 1;
                for (int i = 0; i < pos; i++)
                    p *= 3;
                long long cost = 3 * p;
                if (pos > 0)
                    cost += 1LL * pos * (p / 3);
                ans += cost;
            }
            n /= 3;
            pos++;
        }
        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
