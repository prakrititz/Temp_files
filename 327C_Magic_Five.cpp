#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;  
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % mod; 
        }
        base = (base * base) % mod; 
        exp /= 2;                 
    }
    return result;
}

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long ans = 0;
        string s;
        int k; 
        cin >> s;
        cin >> k; 
        long long n = s.size(); 
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' || s[i] == '5') {
                ans = (ans + mod_pow(2, i, MOD)) % MOD;
            }
        }
        long long d = mod_pow(2, n, MOD);
        long long geometric_sum = (mod_pow(d, k, MOD) - 1 + MOD) % MOD;
        geometric_sum = (geometric_sum * mod_pow(d - 1, MOD - 2, MOD)) % MOD;

        long long final = (ans * geometric_sum) % MOD;
        cout << final << endl;

        return 0;
    }
