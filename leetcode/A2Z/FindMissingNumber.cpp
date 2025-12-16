#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long x = accumulate(nums.begin(), nums.end(), 0ll);
        int m = nums.size();
        return (m*(m+1))/2 - x;
    }
};
void solve();

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