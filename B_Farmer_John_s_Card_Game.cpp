#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> maxCards;
        vector<vector<int>> decks(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> decks[i][j];
            }
            sort(decks[i].begin(), decks[i].end());
            maxCards.push_back({decks[i].back(), i});
        }
        sort(maxCards.begin(), maxCards.end());
        vector<int> order;
        for (auto &p : maxCards) {
            order.push_back(p.second);
        }

        vector<int> indices(n, 0);
        int topCard = -1;
        bool valid = true;

        for (int round = 0; round < m && valid; ++round) {
            for (int i : order) {
                while (indices[i] < decks[i].size() && decks[i][indices[i]] <= topCard) {
                    indices[i]++;
                }
                if (indices[i] < decks[i].size()) {
                    topCard = decks[i][indices[i]];
                    indices[i]++;
                } else {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            for (int i = 0; i < n; ++i) {
                cout << order[i] + 1 << " "; 
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
