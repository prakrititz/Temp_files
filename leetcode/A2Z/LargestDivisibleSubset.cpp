#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the largest divisble subset
    vector<int>largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>parent(n, -1);
        vector<int> dp(n, 1);
        int ans = 1;
        int last = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j]+1>dp[i])
                    {
                        parent[i] = j;
                        dp[i] = dp[j]+1;
                    }
                }
                if(dp[i]>ans)
                {
                    ans = dp[i];
                    last = i;
                }
            }
        }
        vector<int>x;
        while(last!=-1){
            x.push_back(nums[last]);
            last = parent[last];
        }
        return x;
    }
};


int main() {
    vector<int> nums = {15,9,18,54,108,540,90,180,360,720};
    
    // Creating an object of Solution class
    Solution sol;
    vector<int> ans = sol.largestDivisibleSubset(nums);
    // int ans = sol.largestDivisibleSubset(nums);
    
    cout << "The largest divisible subset is: ";
    for(int x : ans) cout << x << " ";
    // cout<<ans<<endl;
    return 0;
}