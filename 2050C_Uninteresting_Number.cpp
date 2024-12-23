#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string n;
        cin >> n;
        int sum = 0;
        int count2 = 0;
        int count3 = 0;
        
        for(char c : n) {
            int digit = c - '0';
            if(digit == 2) count2++;
            if(digit == 3) count3++;
            sum += digit;
        }
        
        bool possible = false;
        int originalSum = sum;
        for(int i = 0; i <= count2; i++) {
            for(int j = 0; j <= count3; j++) {
                sum = originalSum + i * 2 + j * 6;
                if(sum % 9 == 0) {
                    possible = true;
                    break;
                }
            }
            if(possible) break;
        }
        
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}
