#include <bits/stdc++.h>
using namespace std;

vector<long long> primes;
void sieve(long long n)
{
    vector<bool> is_prime(n + 1, true);
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

const long long max_n = 10000000;
vector<long long> ans;
vector<long long> prefix;

void precompute()
{
    ans = vector<long long>(max_n + 1, 0);
    for (long long p : primes)
    {
        for (long long m = p; m <= max_n; m += p)
        {
            ans[m] += 1;
        }
    }
    prefix = vector<long long>(max_n + 1, 0);
    for (long long n = 2; n <= max_n; ++n)
    {
        prefix[n] = prefix[n - 1] + ans[n];
    }
}

void solve()
{
    long long n;
    cin >> n;
    cout << prefix[n] << endl;
}

int main()
{
    sieve(max_n);
    precompute();
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