#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> coins{1, 4, 7, 13, 28, 52, 91, 365};
    
    for (int i = 365; i <= 365 + 91; i++) {
        int target = i;
        vector<int> used_coins;
        
        for (int j = coins.size() - 1; j >= 0; j--) {
            while (target >= coins[j]) {
                target -= coins[j];
                used_coins.push_back(coins[j]);
            }
        }

        cout << "i = " << i << " -> ";
        if (target == 0) {
            for (int coin : used_coins) {
                cout << coin << " ";
            }
            cout << "\n";
        } else {
            cout << "Not possible\n";
        }
    }

    return 0;
}
