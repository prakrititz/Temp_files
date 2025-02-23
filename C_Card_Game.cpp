#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353; // Given MOD value, must be a prime for Fermat’s theorem to work.
const int MAX_N = 1e5 + 5; // Maximum limit for factorial precomputation (adjust as needed)

vector<long long> fact(MAX_N), invFact(MAX_N); // Arrays to store factorials and their modular inverses

// Function to perform modular exponentiation: (x^y) % mod
// This is used to compute modular inverse using Fermat’s Theorem
long long power(long long x, long long y, long long mod)
{
    long long res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod; // If current exponent bit is 1, multiply by base
        x = x * x % mod;         // Square the base (exponentiation by squaring)
        y >>= 1;                 // Right shift the exponent (y = y / 2)
    }
    return res;
}

// Precompute factorials and their modular inverses
void precompute()
{
    fact[0] = invFact[0] = 1; // Base case: 0! = 1
    for (int i = 1; i < MAX_N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD; // Compute factorial iteratively under MOD
    }
    // Compute inverse factorial for last number using Fermat's Theorem
    invFact[MAX_N - 1] = power(fact[MAX_N - 1], MOD - 2, MOD);

    // Compute all inverse factorials in reverse order
    for (int i = MAX_N - 2; i >= 1; i--)
    {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD; // Using invFact[i] = invFact[i+1] * (i+1) % MOD
    }
}

// Compute nCr % MOD efficiently using precomputed factorials
long long choose(int n, int r)
{
    if (r > n || r < 0)
        return 0; // Edge case: if r > n, return 0 (invalid combination)

    // Using formula: nCr % MOD = (fact[n] * invFact[r] * invFact[n-r]) % MOD
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

// Recursive function to compute the required values
vector<long long> calc(int n)
{
    if (n == 2)
    {
        return {1, 0, 1}; // Base case for smallest n
    }

    vector<long long> prev = calc(n - 2); // Recursive call for (n-2)
    vector<long long> result = {
        (choose(n - 1, n / 2) + prev[1]) % MOD, // Compute first value using binomial coefficient
        (choose(n - 2, n / 2) + prev[0]) % MOD, // Compute second value
        1};                                     // Third value is always 1
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute(); // Precompute factorials and inverses for efficient nCr calculations

    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        int n;
        cin >> n;                                                          // Read input value
        vector<long long> result = calc(n);                                // Compute the result using the recursive function
        cout << result[0] << " " << result[1] << " " << result[2] << "\n"; // Print the output
    }

    return 0;
}
