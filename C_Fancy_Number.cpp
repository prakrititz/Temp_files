#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    long long min_cost = LLONG_MAX;
    string best_number;
    for (char d = '0'; d <= '9'; ++d) {
        vector<pair<int, int>> cost_index; // {cost, index}
        for (int i = 0; i < n; ++i) {
            int cost = abs(s[i] - d);
            cost_index.push_back({cost, i});
        }

        sort(cost_index.begin(), cost_index.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        long long total_cost = 0;
        for (int i = 0; i < k; ++i) {
            total_cost += cost_index[i].first;
        }
        if (total_cost < min_cost) {
            min_cost = total_cost;
            best_number = s;
            for (int i = 0; i < k; ++i) {
                best_number[cost_index[i].second] = d;
            }
        }
        else if (total_cost == min_cost) {
            string candidate = s;
            for (int i = 0; i < k; ++i) {
                candidate[cost_index[i].second] = d;
            }
            if (candidate < best_number) {
                best_number = candidate;
            }
        }
    }

    cout << min_cost << endl;
    cout << best_number << endl;

    return 0;
}