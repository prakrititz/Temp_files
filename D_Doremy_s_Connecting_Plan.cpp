#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, c;
    cin >> n >> c;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    long long sum = a[0];
    bool flag = false;
    vector<long long> pre(n);
    pre[0] = a[0];
    for (long long i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    for (long long i = 1; i < n; i++)
    {
        if (sum + a[i] >= c * (i + 1))
        {
            sum = pre[i];
            if (i == n - 1)
                flag = true;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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