#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXK = 100001;

vector<int> spf(MAXK); // smallest prime factor array

// Precompute smallest prime factors using modified sieve
void sieve() {
    for (int i = 1; i < MAXK; i++) spf[i] = i;
    for (int i = 2; i * i < MAXK; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXK; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

// Fast modular exponentiation
ll power(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

// Get prime factorization using precomputed spf
vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> factors;
    int curr_prime = spf[n];
    int curr_count = 0;
    
    while (n > 1) {
        if (spf[n] == curr_prime) {
            curr_count++;
        } else {
            factors.push_back({curr_prime, curr_count});
            curr_prime = spf[n];
            curr_count = 1;
        }
        n /= spf[n];
    }
    factors.push_back({curr_prime, curr_count});
    return factors;
}

// Calculate nCr modulo MOD using Lucas Theorem
ll nCr(ll n, ll r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r == 1) return n % MOD;
    
    vector<ll> fact(n + 1), inv(n + 1), finv(n + 1);
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for (ll i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
    
    return fact[n] * finv[r] % MOD * finv[n - r] % MOD;
}

// Calculate number of ways for given prime power distribution
ll calc_ways(int prime_exp, ll len) {
    // Using stars and bars theorem with optimization
    if (len == 1) return 1;
    return nCr(prime_exp + len - 1, len - 1);
}

void solve() {
    int k;
    ll n;
    cin >> k >> n;
    
    vector<ll> result(k);
    
    // Handle x = 1 case
    result[0] = n % MOD;
    
    // For each number from 2 to k
    for (int x = 2; x <= k; x++) {
        ll ways = 0;
        auto factors = factorize(x);
        
        // For each possible length from 1 to min(n, number of factors)
        ll max_len = min(n, (ll)accumulate(factors.begin(), factors.end(), 0LL, 
                        [](ll sum, const pair<int, int>& p) { return sum + p.second; }));
        
        for (ll len = 1; len <= max_len; len++) {
            ll curr = 1;
            // For each prime factor
            for (auto [prime, exp] : factors) {
                curr = (curr * calc_ways(exp, len)) % MOD;
            }
            ways = (ways + curr) % MOD;
        }
        result[x-1] = ways;
    }
    
    // Print result
    for (int i = 0; i < k; i++) {
        cout << result[i] << " \n"[i == k-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve(); // Precompute smallest prime factors
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}