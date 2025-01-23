#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    vector<long long> values(n);
    long long totalSum = 0;

    for (long long i = 0; i < n; i++) {
        cin >> values[i];
        totalSum += values[i];
    }

    string dir;
    cin >> dir;

    long long result = 0;
    long long left = 0, right = n - 1;

    while (right > left) {
        while (dir[left] == 'R') {
            totalSum -= values[left];
            left++;
        }
        while (dir[right] == 'L') {
            totalSum -= values[right];
            right--;
        }
        if (right < left) break;

        result += totalSum;
        totalSum -= values[left];
        left++;
        totalSum -= values[right];
        right--;
    }

    cout << result << endl;

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