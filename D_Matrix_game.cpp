#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const int MAX_N = 2e5 + 5;

vector<long long> fact(MAX_N);
vector<long long> inv_fact(MAX_N);
vector<long long> inv(MAX_N); 
long long mod_pow(long long base, long long exp)
{
    long long res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

long long mod_inverse(long long n)
{
    return mod_pow(n, mod - 2);
}

void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    
    inv[1] = 1;
    for (int i = 2; i < MAX_N; i++)
    {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod; 
    }
    
    for (int i = 0; i < MAX_N; i++)
    {
        inv_fact[i] = mod_inverse(fact[i]);
    }
}

void solve()
{
    long long a, b, k;
    cin >> a >> b >> k;
    
    long long d = (k * a - k + 1) % mod;
    long long ans = k % mod;
    
    for (long long i = 1; i <= a; i++)
    {
        ans = (ans * ((d - i + 1) % mod)) % mod;
        ans = (ans * inv[i]) % mod; 
    }
    
    ans = ((ans * b - ans + 1) % mod + mod) % mod;
    
    cout << d % mod << ' ' << ans << endl;
}

int main()
{
    precompute();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}