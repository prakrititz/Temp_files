#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to solve the rod cutting problem
int rodCutting(vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);

    for(int len = 1; len <= n; len++) {
        for(int cut = 1; cut <= len; cut++) {
            dp[len] = max(dp[len],
                         dp[len - cut] + price[cut - 1]);
        }
    }

    return dp[n];
}
};


int main() {
    vector<int> price = {2, 4, 6, 8};
    int n = price.size();

    // Create an instance of Solution class
    Solution sol;

    // Print the result
    cout << "The Maximum value is " << sol.rodCutting(price, n) << endl;

    return 0;
}
