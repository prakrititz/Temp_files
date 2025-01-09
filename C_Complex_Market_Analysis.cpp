#include <bits/stdc++.h>
using namespace std;
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
bool isPrime(const vector<bool>& sieve, int n) {
    if (n < 0 || n >= sieve.size()) return false;
    return sieve[n];
}

int main() {
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
        long long ans = 0;
        int i = 0;
        vector<pair<long long, long long>>count_lR(n);
        
        while (i < n) {
            if(isPrime(sieve, a[i])) {
                long long count = 0;
                int ind = i + e;
                while(ind < n && a[ind] == 1) {
                    count++;
                    ind += e;
                }
                count_lR[i].second = count;
            }
            i++;
        }
        
        i = n-1;
        while(i >= 0) {
            if(isPrime(sieve, a[i])) {
                long long count = 0;
                int ind = i - e;
                while(ind >= 0 && a[ind] == 1) {
                    count++;
                    ind -= e;
                }
                count_lR[i].first = count;
            }
            i--;
        }
        
        for(int i = 0; i < n; i++) {
            if(isPrime(sieve, a[i])) {
                ans += count_lR[i].first * count_lR[i].second + count_lR[i].first + count_lR[i].second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}