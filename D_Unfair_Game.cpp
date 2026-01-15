#include<bits/stdc++.h>
using namespace std;
#define int long long 
int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    
    int res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}
void solve() {
    int n, k;
    cin >> n >> k;
    
    // Find d such that n = 2^d
    // Since n is a power of 2, d is simply the number of trailing zeros
    // or log2(n).
    int len = 0;
    int t = n;
    while (t > 1) {
        t /=2;
        len++;
    }

    int ans= 0;

    // Iterate through all bit lengths L from 1 to len
    // These cover all numbers strictly less than n (since n = 2^len)
    for (int L = 1; L <= len; ++L) {
        // For a number with length L:
        // The MSB is fixed at 1.
        // There are L - 1 remaining bits that can be 0 or 1.
        // Let j be the number of set bits in these L-1 positions.
        // Total set bits = 1 + j.
        // Cost = (L - 1) + (1 + j) = L + j.
        
        // We need Cost > k  =>  L + j > k  =>  j > k - L.
        // So j must range from max(0, k - L + 1) to L - 1.
        
        int max_j = L - 1;
        int min_j = max(0LL, (k - L + 1));

        for (int j = min_j; j <= max_j; ++j) {
            ans+= nCr(L - 1, j);
        }
    }

    // Special check for n itself
    // n = 2^len (e.g., 1000...)
    // Bit length = len + 1
    // Popcount = 1
    // Cost = (len + 1 - 1) + 1 = len + 1
    if (len + 1 > k) {
        ans++;
    }

    cout << ans<< endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}