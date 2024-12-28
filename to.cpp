#include<bits/stdc++.h>
using namespace std;
bool willOverflow(long long a, long long b) {
    if (a == 0 || b == 0) return false;
    return a > LLONG_MAX / b;
}
long long safePow(long long k, int n) {
    long long result = 1;
    for(int i = 0; i < n; i++) {
        if(willOverflow(result, k)) return -1;
        result *= k;
    }
    return result;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        long long k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        long long ans = 0;
        
        if(k == 1) {
            long long overlap_start = max(l1, l2);
            long long overlap_end = min(r1, r2);
            ans = max(0LL, overlap_end - overlap_start + 1);
        } else {
            for(int i = 0; i <= 32; i++) {
                long long s = safePow(k, i);
                if(s == -1 || s > r2) break;  
                
               
                long long left = (l2 + s - 1) / s;  
                long long right = r2 / s;
                
                
                left = max(left, l1);
                right = min(right, r1);
                
                if(left <= right) {
                    ans += right - left + 1;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}