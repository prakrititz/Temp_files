#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    long long s;
    long long x;
    cin >> n >> s >> x;

    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    map<long long, long long> mp;
    mp[0] = 1;
    long long sum = 0;
    long long cnt = 0;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            mp.clear();
            mp[0] = 1;

            sum = 0;
            continue; 
        }
        sum += a[i];
        long long target = sum - s;
        if (mp.count(target))
        {
            cnt += mp[target];
        }
        mp[sum]++;
    }
    mp.clear();
    mp[0] = 1;
    sum = 0;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] > x - 1)
        {
            mp.clear();
            mp[0] = 1;
            sum = 0;
            continue; 
        }
        sum += a[i];
        long long target = sum - s;
        if (mp.count(target))
        {
            cnt -= mp[target];
        }
        mp[sum]++;
    }
    cout << cnt << endl;
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
