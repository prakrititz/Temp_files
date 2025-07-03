#include <bits/stdc++.h>
using namespace std;
vector<long long> primes;
vector<bool> is_prime(1e6, true);
vector<int> lar(1e6);
void precompute(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (lar[i] == 0)
        {
            for (int j = i; j <= n; j += i)
            {
                lar[j] = i;
            }
        }
    }
}
void sieve(long long n)
{
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (long long j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (long long i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    map<int, vector<int>> mp;
    vector<int> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (2 * a[i] > n && is_prime[a[i]])
        {
            ans[i] = a[i];
            continue;
        }
        mp[lar[a[i]]].push_back(a[i]);
    }
    for (auto it : mp)
    {
        vector<int> temp;
        for (int i = 1; i < it.second.size(); i++)
            temp.push_back(it.second[i]);
        temp.push_back(it.second[0]);
        for (int i = 0; i < temp.size(); i++)
        {
            ans[it.second[i] - 1] = temp[i];
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    sieve(1e6);
    precompute(1e5);
    while (t--)
    {
        solve();
    }

    return 0;
}