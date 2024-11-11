#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> gr(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    int groupCount = 0;
    while (true) {
        vector<int> singleConnection;
        for (int i = 1; i <= n; i++) {
            if (gr[i].size() == 1) {
                singleConnection.push_back(i);
            }
        }
        if (singleConnection.empty()) {
            break;
        }
        for (int student : singleConnection) {
            int neighbor = gr[student][0];
            gr[neighbor].erase(remove(gr[neighbor].begin(), gr[neighbor].end(), student), gr[neighbor].end());
            gr[student].clear();
        }
        groupCount++;
    }

    cout << groupCount << endl;
    return 0;
}