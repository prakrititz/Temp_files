#include <bits/stdc++.h>
using namespace std;
bool check(vector<long long> &a, long long k)
{
    long long n = a.size();
    bool t = false;
    long long count = 0;
    long long f = -1;
    long long m = -1;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] <= k)
            count++;
        if ((i + 2) / 2 == count)
        {
            f = i;
            break;
        }
    }
    if (f != -1 && f != n - 1)
    {
        if (f < n - 3 && f % 2 == 0 && a[f + 1] > k)
            f++;
        count = 0;
        int size = 0;
        for (long long i = f + 1; i < n - 1; i++)
        {
            size++;
            if (a[i] <= k)
                count++;
            if ((size + 1) / 2 == count)
            {
                m = i;
                break;
            }
        }
        if (m != -1)
        {
            t = true;
        }
    }
    return t;
}
void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    bool s = check(a, k);
    reverse(a.begin(), a.end());
    bool t = check(a, k);
    reverse(a.begin(), a.end());
    bool u = false;
    long long count = 0;
    long long f = -1, l = -1;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] <= k)
            count++;
        if ((i + 2) / 2 == count)
        {
            f = i;
            break;
        }
    }
    long long size = 0;
    if (f != -1)
    {
        count = 0;
        for (long long i = n - 1; i > f + 1; i--)
        {
            size++;
            if (a[i] <= k)
                count++;
            if ((size + 1) / 2 == count)
            {
                l = i;
                break;
            }
        }
    }
    if (l != -1 && f != -1)
        u = true;
    if (u || s || t)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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