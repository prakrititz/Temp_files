#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> &a, long long val, long long k)
{
    for (long long i = 0; i < a.size(); i++)
    {
        if (a[i] >= val)
            return true;
    }
    for (long long i = 0; i < a.size(); i++)
    {
        bool fla = false;
        long long t = 0;
        long long x = 0;
        for (long long j = i; j < a.size(); j++)
        {
            if (a[j] >= val - x)
            {
                fla = true;
                break;
            }
            else
            {
                t += (val - x) - a[j];
            }
            x++;
        }
        if (fla && t <= k)
            return true;
    }
    return false;
}
void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    long long hi = 1e9;
    long long lo = 1;
    long long ans = *max_element(a.begin(), a.end());
    while (lo < hi)
    {
        long long mid = (lo + hi) / 2;
        if (check(a, mid, k))
        {
            lo = mid + 1;
            ans = max(mid, ans);
        }
        else
        {
            hi = mid;
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