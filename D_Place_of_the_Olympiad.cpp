#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m, k;
    cin >> n >> m >> k;
    long long low = 1, high = m;
    while (low < high)
    {
        long long mid = low + (high - low) / 2;
        long long a = m * mid;
        long long b = mid + 1;
        long long max_desks = (a + b - 1) / b;
        long long total = n * max_desks;
        if (total >= k)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << low << endl;
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