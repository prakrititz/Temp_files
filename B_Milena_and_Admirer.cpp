#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    long long ans = 0;
    vector<long long> temp;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    temp.push_back(a[n - 1]);
    for (long long i = n - 2; i >= 0; i--)
    {
        if (a[i] > temp.back())
        {
            ans += ((a[i] + temp.back() - 1) / temp.back() - 1);
            long long s = (a[i] + temp.back() - 1) / temp.back();
            temp.push_back(a[i] / s);
        }
        else
        {
            temp.push_back(a[i]);
        }
    }
    cout << ans << endl;
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