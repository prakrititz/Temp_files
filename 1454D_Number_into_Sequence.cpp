#include<bits/stdc++.h>
using namespace std;
map<long long, int> prime_factors(long long n) {
    map<long long, int> factors;
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }
    for (long long i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 2) {
        factors[n]++;
    }

    return factors;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;    
        cin >> n;
        map<long long, int> factors = prime_factors(n);
        long long prime_with_max_exp = -1;
        int max_exp = -1;

        for (auto &factor : factors) {
            if (factor.second > max_exp) {
                max_exp = factor.second;
                prime_with_max_exp = factor.first;
            }
        }
        vector<long long> sequence;
        long long ans = 1;
        for (int i = 0; i < max_exp - 1; ++i) {
            ans *= prime_with_max_exp;
            sequence.push_back(prime_with_max_exp);
        }
        sequence.push_back(n/ans);
        cout << sequence.size() << endl;
        for (long long val : sequence) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
