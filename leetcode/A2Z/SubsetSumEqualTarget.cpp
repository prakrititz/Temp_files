#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if there is a subset of 'arr' with sum equal to 'k' using space optimization
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<bool>>dp(n+1, vector<bool>(k+1));
        dp[0][0] = true;
        for(int i = 1;i<=n;i++)
        {
            for(int target = 0;target <= k; target++)
            {
                int take = false;
                if(target>=arr[i-1])
                {
                    take = dp[i-1][target-arr[i-1]];
                }
                int not_take = dp[i-1][target];
                dp[i][target] = take || not_take;
            }
        }
        return dp[n][k];
    }
};

// Driver code
int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    Solution sol;
    if (sol.subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}
