    #include<bits/stdc++.h>
    using namespace std;
    int countAlmostPrimes(int n) {
        vector<int> primeFactors(n + 1, 0);

        // Modified Sieve of Eratosthenes
        for (int i = 2; i <= n; i++) {
            if (primeFactors[i] == 0) { // i is a prime number
                for (int j = i; j <= n; j += i) {
                    primeFactors[j]++;
                }
            }
        }

        // Count numbers with exactly 2 distinct prime factors
        int count = 0;
        for (int i = 2; i <= n; i++) {
            if (primeFactors[i] == 2) {
                count++;
            }
        }

        return count;
    }

    int main() {
        int n;
        cin >> n;
        cout << countAlmostPrimes(n) << endl;
        return 0;
    }
