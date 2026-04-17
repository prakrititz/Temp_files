#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_BITS = 20;

struct Query {
    int l, x, id;
    // Sort queries by their right endpoint l 
    bool operator<(const Query& other) const {
        return l < other.l;
    }
};

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
void solve(){
    int n, q;
    if (!(cin >> n >> q)) return;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].x;
        queries[i].id = i;
    }
    sort(queries.begin(), queries.end());
    vector<int> pivots(MAX_BITS, 0); // this is our "Compressed Matrix"
    int current_rank = 0;           // Number of pivot rows
    vector<long long> answers(q);
    int query_idx = 0;
    for (int i = 1; i <= n; i++) {
        int val = a[i];
        for (int bit = MAX_BITS - 1; bit >= 0; bit--) {
            if ((val >> bit) & 1) {
                if (!pivots[bit]) {
                    pivots[bit] = val;
                    current_rank++;
                    break;
                }
                val ^= pivots[bit];
            }
        }
        while (query_idx < q && queries[query_idx].l == i) {
            int x = queries[query_idx].x;
            int id = queries[query_idx].id;
            // Check: Can X be formed by the current pivots?
            // This is equivalent to checking: Does adding X increase the rank?
            int temp_x = x;
            bool possible = true;
            for (int bit = MAX_BITS - 1; bit >= 0; bit--) {
                if ((temp_x >> bit) & 1) {
                    if (!pivots[bit]) {
                        // X as a pivot bit so its not linearnly indepenedent no solution 
                        possible = false;
                        break;
                    }
                    temp_x ^= pivots[bit];
                }
            }
            if (possible) {
                // X is linearly independent basically rank didnt increase 
                int free_vars = i - current_rank;
                answers[id] = power(2, free_vars);
            } else {
                answers[id] = 0;
            }
            query_idx++;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << answers[i] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }

    return 0;
}