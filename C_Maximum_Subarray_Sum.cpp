#include <bits/stdc++.h>
using namespace std;
long long get(vector<long long> &a)
{
    long long n = a.size();
    long long maxi = LONG_LONG_MIN;
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum <= 0)
        {
            sum = 0;
        }
        maxi = max(sum, maxi);
    }
    maxi = max(sum, maxi);
    return maxi;
}
void solve()
{
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long count = 0;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        count += (s[i] == '0');
        cin >> a[i];
        if (s[i] == '0')
            a[i] = -1e18;
    }
    long long maxi = get(a);
    if (count == 0)
    {
        if (maxi != k)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            cout << "YES" << endl;
            for (long long i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            return;
        }
    }
    else if (count != 0 && maxi > k)
    {
        cout << "NO" << endl;
        return;
    }
    long long pos = s.find('0');
    if (pos != -1)
    {
        a[pos] = 1e18;
        long long val = get(a);
        a[pos] = a[pos] - (val - k);
        cout << "YES" << endl;
        for (long long i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
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