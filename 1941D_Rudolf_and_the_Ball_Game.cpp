#include <bits/stdc++.h>
using namespace std;

int main() {

 int t; 
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        set<int> q = {x};
        for (int i = 0; i < m; i++) {
            int r;
            char c;
            cin >> r >> c;

            set<int> new_q;

            for (int pos : q) {
                if (c == '0' || c == '?') {
                    int clockwise_pos = ((pos + r - 1) % n) + 1;
                    new_q.insert(clockwise_pos);
                }
                if (c == '1' || c == '?') {
                    int counterclockwise_pos = ((pos - r - 1 + n) % n) + 1;
                    new_q.insert(counterclockwise_pos);
                }
            }
            q = new_q;
        }

        cout << q.size() << "\n";
        for (int pos : q) {
            cout << pos << " ";
        }
        cout << "\n";
    }

    return 0;
}
