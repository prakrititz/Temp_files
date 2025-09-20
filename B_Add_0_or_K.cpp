#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long k;
    cin >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];

    for (long long i = 0; i < n; i++)
    {
        if (k >= a[i])
        {
            a[i] = (k + 1) * a[i];
            continue;
        }
        a[i] = a[i] + (a[i] % (k + 1)) * k;
    }
    for (long long i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
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