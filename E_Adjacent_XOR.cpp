#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    for (long long i = 0; i < n; i++)
        cin >> b[i];
    if (a[n - 1] != b[n - 1])
    {
        cout << "NO" << endl;
        return;
    }
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
        v[i] = a[i];
    for (long long i = n - 2; i >= 0; i--)
    {
        if (a[i] != b[i])
        {

            if ((a[i] ^ a[i + 1]) == b[i])
            {

                continue;
            }
            else if ((a[i] ^ b[i + 1]) == b[i])
            {

                continue;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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