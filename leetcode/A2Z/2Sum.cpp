#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        int k = target;
        map<int, int>mp;
        vector<int>ans;
        for(int j = 0;j<n ;j++)
        {   
            sum = nums[j];
            if(mp.find(k-sum)!=mp.end())
            {
                int s = mp[k-sum];
                ans.push_back(s);
                ans.push_back(j);
            }
            mp[sum]=j;
        }
        return ans;
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