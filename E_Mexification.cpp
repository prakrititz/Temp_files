#include <bits/stdc++.h>
using namespace std;
vector<long long> findmex(vector<long long> &a)
{
    long long n = a.size();
    vector<long long> f(n + 2, 0);
    for (long long x : a)
    {
        if (x >= 0 && x < n + 2)
        {
            f[x]++;
        }
    }
    long long m = 0;
    while (m < n + 2 && f[m] > 0)
    {
        m++;
    }
    vector<long long> r(n);
    for (long long i = 0; i < n; i++)
    {
        long long x = a[i];
        if (x >= 0 && x < n + 2)
        {
            if (f[x] > 1)
            {
                r[i] = m;
            }
            else
            {
                if (x < m)
                {
                    r[i] = x;
                }
                else
                {
                    r[i] = m;
                }
            }
        }
        else
        {
            r[i] = m;
        }
    }
    return r;
}

long long sum(vector<long long> &v)
{
    long long s = 0;
    for (int i = 0; i < v.size(); i++)
        s += v[i];
    return s;
}

void solve()
{
    long long n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];

    if (k == 0)
    {
        cout << sum(a) << endl;
        return;
    }

    vector<long long> a1 = findmex(a);
    if (k == 1)
    {
        cout << sum(a1) << endl;
        return;
    }

    vector<long long> a2 = findmex(a1);
    if (a1 == a2)
    {
        cout << sum(a2) << endl;
        return;
    }

    vector<long long> a3 = findmex(a2);
    if (a2 == a3)
    {
        cout << sum(a3) << endl;
        return;
    }

    if (a1 == a3)
    {
        if (k % 2 == 1)
            cout << sum(a1) << endl;
        else
            cout << sum(a2) << endl;
    }
    else
    {
        if (k % 2 == 0)
            cout << sum(a2) << endl;
        else
            cout << sum(a3) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--)
        solve();
}
