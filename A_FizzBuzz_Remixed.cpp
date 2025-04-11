#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long complete_cycles = n / 15;
    long long remainder = n % 15;
    long long count = complete_cycles * 3;
    long long extra = min(remainder + 1, 3LL);
    count += extra;
    cout << count << endl;
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