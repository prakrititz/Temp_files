#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<long long> pre(n);
    pre[0] = a[0];
    bool flag = true;
    for (long long i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
        if (pre[i - 1] < a[i])
            flag = false;
    }
    if (a[0] != 1)
        flag = false;
    if (flag)
        cout << "YES";
    else
        cout << "NO";
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