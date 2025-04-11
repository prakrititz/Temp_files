#include <bits/stdc++.h>
using namespace std;
set<long long> topo;

void precompute()
{
    for (int i = 2; i <= 1000000; i++)
    {
        long long mini = 1 + i + (long long)i * i;
        topo.insert(mini);
        long long p = (long long)i * i * i;
        while (mini <= 1e18 / i)
        {
            mini += p;
            topo.insert(mini);
            if (p > 1e18 / i)
                break;
            p *= i;
        }
    }
}

void solve()
{
    long long n;
    cin >> n;
    if (n <= 3)
    {
        cout << "NO" << endl;
        return;
    }
    if (topo.count(n))
    {
        cout << "YES" << endl;
        return;
    }
    long double d = 4 * (long double)n - 3;
    long double val = (sqrt(d) - 1) / 2.0;
    if (val == (long long)val)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}