#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6;

vector<long long> fact(MAXN + 1, 1), invFact(MAXN + 1, 1);

long long modPow(long long base, long long exp, long long mod)
{
    long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void precomputeFactorials()
{
    for (int i = 2; i <= MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN] = modPow(fact[MAXN], MOD - 2, MOD);
    for (int i = MAXN - 1; i >= 1; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long Comb(long long n, long long k)
{
    if (k > n || k < 0)
        return 0;
    return (fact[n] * invFact[k] % MOD) * invFact[n - k] % MOD;
}

void solve()
{
    vector<long long> c(26);
    for (long long i = 0; i < 26; i++)
    {
        cin >> c[i];
    }
    long long n = accumulate(c.begin(), c.end(), 0);
    long long odd_positions = (n + 1) / 2;
    long long even_positions = n / 2;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (long long i = 0; i < c.size(); i++)
    {
        long long freq = c[i];
        if (freq == 0)
            continue;
        vector<long long> new_dp(n + 1, 0);
        for (long long j = 0; j < n + 1; j++)
        {
            if (dp[j] == 0)
                continue;
            new_dp[j] = (new_dp[j] + dp[j]) % MOD;// I am not using this letter
            if (j + freq <= n)
            {
                new_dp[j + freq] = (new_dp[j + freq] + dp[j]) % MOD;// i m using this letter
            }
        }
        dp = new_dp;
    }
    long long result = dp[odd_positions];
    long long odd_fact = fact[odd_positions];
    long long even_fact = fact[even_positions];
    long long denom = 1;
    for (auto freq : c)
    {
        if (freq > 0)
            denom = denom * invFact[freq] % MOD;
    }
    result = result * odd_fact % MOD * even_fact % MOD * denom % MOD;
    cout << result << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    precomputeFactorials();
    while (t--)
    {
        solve();
    }

    return 0;
}
