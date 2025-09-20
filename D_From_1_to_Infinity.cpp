#include <bits/stdc++.h>
using namespace std;

long long sum(long long n)
{
    if (n < 10)
        return n * (n + 1) / 2;
    string s = to_string(n);
    int len = s.size();
    long long first = s[0] - '0';
    long long p = 1;
    for (int i = 1; i < len; i++)
        p *= 10;
    long long res = first * sum(p - 1) + (first * (first - 1) / 2) * p + first * (n % p + 1) + sum(n % p);
    return res;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long k;
        cin >> k;
        long long ans = 0;
        long long d = 1, cnt, len;
        while (true)
        {
            cnt = 9;
            for (int i = 1; i < d; i++)
                cnt *= 10;
            len = cnt * d;
            if (k > len)
            {
                long long start = 1;
                for (int i = 1; i < d; i++)
                    start *= 10;
                long long end = start + cnt - 1;
                ans += sum(end) - sum(start - 1);
                k -= len;
                d++;
            }
            else
            {
                long long start = 1;
                for (int i = 1; i < d; i++)
                    start *= 10;
                long long full = k / d;
                long long rem = k % d;
                if (full > 0)
                {
                    ans += sum(start + full - 1) - sum(start - 1);
                }
                if (rem > 0)
                {
                    long long num = start + full;
                    string s = to_string(num);
                    for (int i = 0; i < rem; i++)
                        ans += s[i] - '0';
                }
                break;
            }
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
