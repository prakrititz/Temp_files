#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 998244353;
ll mod_pow(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

map<ll, int> get_prime_factors(ll num) {
    map<ll, int> factors;
    for (ll i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            factors[i]++;
            num /= i;
        }
    }
    if (num > 1) {
        factors[num]++;
    }
    return factors;
}

ll count_ways_for_prime(ll power, ll n) {
    ll result = 0;
    for (ll M = power; M <= power * 2; M++) {
        ll N = M - power;
        ll choices = M - N + 1;
        ll ways = mod_pow(choices, n - 1);
        result = (result + ways) % MOD;
    }
    return result;
}

void solve() {
    ll a1, n;
    cin >> a1 >> n;
    map<ll, int> prime_factors = get_prime_factors(a1);
    ll ans = 1;
    for (auto [prime, power] : prime_factors) {
        ans = (ans * count_ways_for_prime(power, n)) % MOD;
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}