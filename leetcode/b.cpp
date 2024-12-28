#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;
        
        long long cycleSum = a + b + c;
        long long completeCycles = (n - 1) / cycleSum;
        long long remainingDist = n - completeCycles * cycleSum;
        long long days = completeCycles * 3;
        if(remainingDist <= 0) {
            cout << days << "\n";
            continue;
        }
        
        long long curr = 0;
        if(curr + a >= remainingDist) {
            cout << days + 1 << "\n";
            continue;
        }
        curr += a;
        
        if(curr + b >= remainingDist) {
            cout << days + 2 << "\n";
            continue;
        }
        curr += b;
        
        cout << days + 3 << "\n";
    }
    return 0;
}
