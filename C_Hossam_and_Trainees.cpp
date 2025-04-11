#include <bits/stdc++.h>
using namespace std;

vector<long long> primes;
vector<bool> is_prime(1e6, true);
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
    long long n;
    cin >> n;
    set<long long> st;
    vector<long long> a(n);
    map<long long, int> mp;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    // for (auto it : mp)
    // {
    //     if (it.second >= 2 && it.first != 1)
    //     {
    //         cout << "YES" << endl;
    //         return;
    //     }
    // }
    // sort(a.begin(), a.end());
    for (long long i = 0; i < n; i++)
    {
        int temp = a[i];
        for (long long j = 0; j < primes.size(); j++)
        {
            if (primes[j] > a[i])
                break;
            if (a[i] % primes[j] == 0)
            {

                if (!st.empty() && st.find(primes[j]) != st.end())
                {
                    cout << "YES" << endl;
                    return;
                }
                st.insert(primes[j]);
                while (a[i] % primes[j] == 0)
                {
                    a[i] /= primes[j];
                }
            }
        }
        if (a[i] != 1)
        {
            if (!st.empty() && st.find(a[i]) != st.end())
            {
                cout << "YES" << endl;
                return;
            }
            st.insert(a[i]);
        }
    }
    cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    sieve(31623);
    while (t--)
    {
        solve();
    }

    return 0;
}