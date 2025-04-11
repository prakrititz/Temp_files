#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
const int MAX_N = 2e5 + 5;

vector<long long> fact(MAX_N);
vector<long long> inv_fact(MAX_N);

long long mod_pow(long long base, long long exp) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

long long mod_inverse(long long n) {
    return mod_pow(n, mod - 2);
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    
    for (int i = 0; i < MAX_N; i++) {
        inv_fact[i] = mod_inverse(fact[i]);
    }
}

void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long m1 = 0;
    long long mini = INT_MAX;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        m1 = max(m1, a[i]);
        mini = min(mini, a[i]);
    }
    bool t = false;
    long long M = 0;
    long long M1 = 0;
    long long O = 0;
    for (long long i = 0; i < n; i++) {
        if (a[i] == m1 - 1) {
            M1++;
            t = true;
        }
        else if (a[i] == m1) {
            M++;
        }
        else {
            O++;
        }
    }
    if (M >= 2) {
        cout << fact[n] << endl;
        return;
    }
    if (!t && m1 != mini) {
        cout << 0 << endl;
        return;
    }
    else {
        long long ans = 0;
        for (long long i = O + 1; i > 0; i--) {
            long long ocount = i - 1;
            long long twocount = M;
            
            long long aftertw0;
            if (ocount == 0)
                aftertw0 = 1;
            else {
                aftertw0 = (fact[O] * inv_fact[O - ocount]) % mod;
            }
            
            long long term = (fact[n - i] * aftertw0) % mod;
            term = (term * twocount) % mod;
            ans = (ans + term) % mod;
        }
        ans = (fact[n] - ans + mod) % mod;
        
        cout << ans << endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();
    
    long long t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}