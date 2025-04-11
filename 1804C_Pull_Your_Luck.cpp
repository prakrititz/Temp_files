#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x, p;
    cin >> n >> x >> p;
    int sum = 0;

    // the logic here is that it repeats  after 2n permutations , 
    for (int i = 1; i <= min(p, 2 * n); i++)
    {
        sum += i;
        sum %= n;
        if (sum == (n - x) % n)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
    return;
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