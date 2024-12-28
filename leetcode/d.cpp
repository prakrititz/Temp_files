#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        
        vector<long long> a(n);
        long long total = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
        }
        sort(a.begin(), a.end());
        
        long long count = 0;
        for(int i = 0; i < n-1; i++) {
            long long need_min = total - y;
            long long need_max = total - x;
            auto left = lower_bound(a.begin() + i + 1, a.end(), 
                                  need_min - a[i]);
            auto right = upper_bound(a.begin() + i + 1, a.end(), 
                                   need_max - a[i]);
            
            count += right - left;
        }
        
        cout << count << "\n";
    }
    return 0;
}