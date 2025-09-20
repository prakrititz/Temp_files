#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, A, B;
    if (!(cin >> N >> A >> B)) return 0;
    int m = B - A + 1;
    vector<double> E(N + 1, 0.0); // E[N] = 0
    vector<double> pref(N + 1, 0.0); // pref[i] = E[i] + pref[i+1], pref[N] = 0

    // compute E[s] for s = N-1 .. 0
    for (int s = N - 1; s >= 0; --s) {
        if (A == 0) {   
            // sum over k = 1..B of E[s+k] but only those with s+k < N
            int l = s + 1;
            int r = min(N - 1, s + B);
            double sum_rest = 0.0;
            if (l <= r) sum_rest = pref[l] - pref[r + 1];
            // E[s] = (m + sum_rest) / (m - 1)
            E[s] = (m + sum_rest) / double(m - 1);
        } else {
            // sum over k = A..B of E[s+k] but only for s+k < N
            int l = s + A;
            int r = min(N - 1, s + B);
            double sum_block = 0.0;
            if (l <= r) sum_block = pref[l] - pref[r + 1];
            E[s] = 1.0 + sum_block / double(m);
        }
        pref[s] = E[s] + pref[s + 1];
    }

    cout.setf(std::ios::fixed); 
    cout << setprecision(5) << E[0] << "\n";
    return 0;
}
