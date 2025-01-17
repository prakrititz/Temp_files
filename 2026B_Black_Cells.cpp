#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n % 2 == 0) {
            long long maxDif = 0;
            for (long long i = 1; i < n; i+=2) {
                maxDif = max(a[i] - a[i-1], maxDif);
            }
            cout << maxDif << endl;
        }
        else {
            if (n == 1) {
                cout << 1 << endl;
            }
            else {
                long long ans = LLONG_MAX;
                for (long long i = 0; i < n; i++) {
                    long long maxDif = 1;
                    long long to_skip = a[i];
                    vector<long long> temp;
                    for (long long j = 0; j < n; j++) {
                        if (a[j] != to_skip)
                            temp.push_back(a[j]);
                    }
                    for (long long j = 1; j < temp.size(); j += 2) {
                        maxDif = max(maxDif, temp[j] - temp[j-1]);
                    }
                    ans = min(maxDif, ans);
                }
                cout << ans << endl;
            }
        }
    }

    return 0;
}
