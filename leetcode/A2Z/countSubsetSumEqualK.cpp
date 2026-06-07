#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubsets(vector<int>& arr, int K) {
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(K+1));
        dp[0][0] = 1;
        for(int i = 1;i<=n;i++)
        {
            for(int target = 0;target <= K; target++)
            {
                int take = 0;
                if(target>=arr[i-1])
                {
                    take = dp[i-1][target-arr[i-1]];
                }
                int not_take = dp[i-1][target];
                dp[i][target] = take + not_take;
            }
        }
        return dp[n][K];
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3, 3};
    int K = 6;
    cout << obj.countSubsets(arr, K) << endl;
    return 0;
}
