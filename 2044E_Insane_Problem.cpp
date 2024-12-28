#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Check if multiplication would overflow
bool willOverflow(ll a, ll b) {
    if (a == 0 || b == 0) return false;
    if (a > LLONG_MAX / b) return true;
    return false;
}

// Calculate k^n safely, returns -1 if overflow
ll power(ll k, ll n) {
    ll result = 1;
    while (n--) {
        if (willOverflow(result, k)) return -1;
        result *= k;
    }
    return result;
}

// Find valid x range for given k^n that satisfies l2 ≤ x*k^n ≤ r2
pair<ll, ll> findValidRange(ll k, ll n, ll l1, ll r1, ll l2, ll r2) {
    ll kn = power(k, n);
    if (kn == -1) return {1, 0}; // Empty range
    
    // Find x range where l2 ≤ x*k^n ≤ r2
    ll left = (l2 + kn - 1) / kn;  // Ceiling division
    ll right = r2 / kn;
    
    // Intersect with [l1, r1]
    left = max(left, l1);
    right = min(right, r1);
    
    return {left, right};
}

ll solve(ll k, ll l1, ll r1, ll l2, ll r2) {
    // Special case for k = 1
    if (k == 1) {
        ll overlap_start = max(l1, l2);
        ll overlap_end = min(r1, r2);
        return max(0LL, overlap_end - overlap_start + 1);
    }
    
    ll result = 0;
    
    // Handle n = 0 (x = y) separately
    ll left = max(l1, l2);
    ll right = min(r1, r2);
    if (left <= right) {
        result += right - left + 1;
    }
    
    // Check all possible powers until k^n exceeds r2
    for (int n = 1; n <= 32; n++) {
        auto [left, right] = findValidRange(k, n, l1, r1, l2, r2);
        if (left <= right) {
            result += right - left + 1;
        }
        
        // Early termination if k^n is too large
        ll kn = power(k, n);-
        if (kn == -1 || kn > r2) break;
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        cout << solve(k, l1, r1, l2, r2) << '\n';
    }
    
    return 0;
}