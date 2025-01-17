#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000; // Maximum possible value of r
vector<int> operations(MAX + 1, 0);
vector<int> prefixSum(MAX + 1, 0);
int noOfOperation(int x){
int count = 0;
while(x>0)
{
    x/=3;
    count++;
}
return count;
}
// Precompute operations and prefix sums
void precompute() {
    for (int i = 1; i <= MAX; ++i) {
        int x = i, count = 0;
        while (x > 0) {
            x /= 3;
            count++;
        }
        operations[i] = count;
        prefixSum[i] = prefixSum[i - 1] + operations[i];
    }
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << prefixSum[r] - prefixSum[l - 1]+noOfOperation(l) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
