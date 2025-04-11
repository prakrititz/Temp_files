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

long long cal(long long x, long long y, long long k)
{
    long long ones = x, zeros = y;
    if (ones < k / 2 + 1)
        return 0;
    long long ans = 0;
    for (long long i = k / 2 + 1; i <= ones; i++)
    {
        long long temp = (Comb(ones, i) * Comb(zeros, k - i)) % MOD;
        ans = (ans + temp) % MOD;
    }
    return ans;
}

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n), o(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        o[i] = a[i];
    }

    for (long long i = 1; i < n; i++)
    {
        o[i] = (o[i] + o[i - 1]) % MOD;
    }

    if (k == 1)
    {
        cout << o[n - 1] << endl;
        return;
    }
    long long ans = cal(o[n - 1], n - o[n - 1], k);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precomputeFactorials();

    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
