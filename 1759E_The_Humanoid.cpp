#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, h;
    cin >> n >> h;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    long long ans = 0;
    vector<vector<long long>> res = {{2, 2, 3}, {3, 2, 2}, {2, 3, 2}};
    for (long long k = 0; k < 3; k++)
    {
        long long h2 = h;
        long long i = 0;
        long long t = 0;
        long long count = 0;
        while (i < n)
        {

            if (h2 > a[i])
            {
                h2 += a[i] / 2;
                count++;
                i++;
            }
            else
            {
                while (h2 <= a[i] && t < 3)
                {
                    h2 *= res[k][t];
                    t++;
                }
                if (h2 > a[i])
                {
                    h2 += a[i] / 2;
                    count++;
                    i++;
                }
                else
                {
                    break;
                }
            }
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}