#include <bits/stdc++.h>
using namespace std;

// Build sieve up to 10^6
vector<bool> buildSieve(int limit) {
    vector<bool> sieve(limit + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

// Check if a number is prime using the sieve
bool isPrime(const vector<bool>& sieve, int n) {
    if (n < 0 || n >= sieve.size()) return false;
    return sieve[n];
}

int main() {
    // Build sieve for primes
    const int LIMIT = 1000000;
    auto sieve = buildSieve(LIMIT);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int>isDone;
        int ans = 0;
        int i = 0;
        while (i < n) {
            if(a[i]==1)
            {
                int curr = 1;
                int count = 0;
                while(a[i+curr*e]==1 || isPrime(a[i+e*curr]))
                {
                    curr ++; 
                    count ++;
                }
            }
            else if(isPrime(a[i]))
            {
                int count = 0; 
                int curr = 1;
                while(a[i+curr*e] == 1)
                {
                    count ++; 
                    curr ++;
                }
                
            }


        }
        cout << ans << endl;
    }

    return 0;
}
