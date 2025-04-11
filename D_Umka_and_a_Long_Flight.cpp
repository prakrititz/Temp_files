#include <bits/stdc++.h>
using namespace std;

vector<long long> fib(100);
void precompute()
{
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 100; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
}
bool s(int n, int x, int y)
{
    if (n == 1)
        return true;
    int h = fib[n];
    int w = fib[n + 1];
    if (fib[n - 1] < y && y <= fib[n])
        return false;
    if (fib[n] < y)
        y -= fib[n];
    return s(n - 1, y, x);
}
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    if (s(n, x, y))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}