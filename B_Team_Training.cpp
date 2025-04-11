#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    long long ans = 0;
    long long i = 0;

    while (i < n)
    {
        if (a[i] >= x)
        {
            ans++;
            i++;
        }
        else
        {

            long long k = 2;
            while (i + k - 1 < n && (long long)k * a[i + k - 1] < x)
            {
                k++;
            }
            if (i + k - 1 < n && (long long)k * a[i + k - 1] >= x)
            {
                ans++;
                i += k;
            }
            else
            {
                break;
            }
        }
    }
    cout << ans << endl;
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