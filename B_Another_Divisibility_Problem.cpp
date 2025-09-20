#include <bits/stdc++.h>
using namespace std;

void solve()
{

    long long x;
    cin >> x;
    string sx = to_string(x);
    int L = sx.size();

    long long pL = 1;
    for (int i = 0; i < L; ++i)
        pL *= 10LL;
    long long t1 = pL - 1;

    long long y = t1 - x;
    if (y <= 0 || (long long)to_string(y).size() != L)
    {
        long long pL1 = pL * 10LL;
        long long t2 = pL1 - 1;
        y = t2 - x;
    }

    cout << y << endl;
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