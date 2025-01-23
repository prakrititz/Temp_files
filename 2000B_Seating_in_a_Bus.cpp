#include <bits/stdc++.h>
using namespace std;

void solve() {
        int passen;
        cin >> passen;
        
        vector<int> seats(passen);
        for (int i = 0; i < passen; ++i) {
            cin >> seats[i];
        }
        unordered_set<int> occupied;
        bool flag = true;
        
        occupied.insert(seats[0]);
        for (int i = 1; i < passen; ++i) {
            int curr = seats[i];
            if (occupied.count(curr - 1) == 0 && 
                occupied.count(curr + 1) == 0) {
                flag = false;
                break;
            }
            occupied.insert(curr);
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}