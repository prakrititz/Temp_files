#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long q;
    cin >> q;

    deque<long long> a;

    long long sum = 0;
    long long ans = 0;

    bool rev = false;

    while (q--)
    {
        long long s;
        cin >> s;

        if (s == 1)
        {
            if (!rev)
            {
                long long x = a.back();
                ans += sum;
                long long size = a.size();
                ans -= size * x;
                a.pop_back();
                a.push_front(x);
            }
            else
            {
                long long x = a.front();
                ans -= sum;
                long long size = a.size();
                ans += size * x;
                a.pop_front();
                a.push_back(x);
            }
        }
        else if (s == 2)
        {
            rev ^= 1;
        }
        else
        {
            long long k;
            cin >> k;
            if (!rev)
            {
                long long size = a.size();
                ans += size * k;
                sum += k;
                a.push_back(k);
            }
            else
            {
                ans += sum;
                sum += k;
                a.push_front(k);
            }
        }

        if (!rev)
        {
            cout << ans + sum << endl;
        }
        else
        {
            long long size = a.size();
            cout << sum * size - ans << endl;
        }
    }
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