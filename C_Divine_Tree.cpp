#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m;
    cin >> n >> m;
    if (m < n || m > (n * (n + 1)) / 2)
    {
        cout << -1 << endl;
        return;
    }
    long long sum = (n * (n + 1)) / 2 - m;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        a[i] = i + 1;
    for (long long i = n - 1; i >= 0; i--)
    {
        if (sum <= a[i] - 1)
        {
            a[i] -= sum;
            sum = 0;
        }
        else
        {
            sum -= (a[i] - 1);
            a[i] = 1;
        }
        if (sum <= 0)
            break;
    }
    long long t = *max_element(a.begin(), a.end());
    cout << t << endl;
    long long i = 0;
    while (i < n)
    {
        if (a[i] == t)
            break;
        cout << i + 1 << " " << t << endl;
        i++;
    }
    i++;
    while (i < n)
    {
        cout << a[i] << " " << i + 1 << endl;
        i++;
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