#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 2e5 + 5;
int inputN[MAX_SIZE];
int charToNumberMapping[26];
bool isCharUsed[26];
map<int, bool> numberAssigned;
void solve() {
    int n; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inputN[i];
    }

    int q; 
    cin >> q;

    for (int i = 1; i <= q; i++) {
        string s; 
        cin >> s;
        numberAssigned.clear();
        if (s.size() != n) {
            cout << "NO" << '\n';
            continue;
        }
        for (int i = 0; i < 26; i++) {
            isCharUsed[i] = false;
        }
        bool isValid = true;

        for (int j = 0; j < n; j++) {
            int charIndex = s[j] - 'a';

            if (!isCharUsed[charIndex]) {
                if (numberAssigned[inputN[j + 1]]) {
                    isValid = false;
                    break;
                }
                numberAssigned[inputN[j + 1]] = true;
                isCharUsed[charIndex] = true;
                charToNumberMapping[charIndex] = inputN[j + 1];
            }

            if (charToNumberMapping[charIndex] != inputN[j + 1]) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}