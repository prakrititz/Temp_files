#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> m(n);
    m[0] = a[0];
    for (long long i = 1; i < n; i++)
    {
        m[i] = max(m[i - 1], a[i]);
    }
    vector<long long> s(n);
    s[n - 1] = a[n - 1];
    for (long long i = n - 2; i >= 0; i--)
    {
        s[i] = a[i] + s[i + 1];
    }
    long long sum = 0;
    vector<long long> ans;
    ans.push_back(m[n - 1]);
    for (long long i = n - 2; i >= 0; i--)
    {
        ans.push_back(s[i + 1] + m[i]);
    }
    for (long long i = 0; i < n; i++)
        cout << ans[i] << " ";
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