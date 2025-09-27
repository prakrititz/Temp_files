#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(k);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    long long sum = 0;
    int i = 0;
    for (auto k : b)
    {
        int count = 0;
        while (i < n && count < k - 1)
        {
            sum += a[i];
            i++;
            count++;
        }
        i++;
    }
    while (i < n)
    {
        sum += a[i];
        i++;
    }
    cout << sum << endl;
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