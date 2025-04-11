#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w, h, n;
    cin >> w >> h >> n;

    set<int> horizontal_cuts = {0, h};
    set<int> vertical_cuts = {0, w};
    multiset<int> horizontal_lengths = {h};
    multiset<int> vertical_lengths = {w};

    for (int i = 0; i < n; ++i) {
        char type;
        int position;
        cin >> type >> position;

        set<int> *cuts;
        multiset<int> *lengths;

        if (type == 'H') {
            cuts = &horizontal_cuts;
            lengths = &horizontal_lengths;
        } else {
            cuts = &vertical_cuts;
            lengths = &vertical_lengths;
        }










        cuts->insert(position);

        auto it = cuts->find(position);
        auto left = prev(it);
        auto right = next(it);

        lengths->erase(lengths->find(*right - *left));

        lengths->insert(position - *left);
        lengths->insert(*right - position);

        long long max_width = *vertical_lengths.rbegin();
        long long max_height = *horizontal_lengths.rbegin();
        cout << max_width * max_height << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
