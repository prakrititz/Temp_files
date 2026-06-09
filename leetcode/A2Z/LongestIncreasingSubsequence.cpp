#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int LIS(vector<int>& nums) {

    vector<int> parent(n, -1);
    vector<int> pos;          // index of element corresponding to ans[k]
    vector<int> ans;

    ans.push_back(nums[0]);
    pos.push_back(0);

    for(int i = 1; i < n; i++)
    {
        int j = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

        if(j == ans.size())
        {
            parent[i] = pos.back();
            ans.push_back(nums[i]);
            pos.push_back(i);
        }
        else
        {
            if(j > 0) parent[i] = pos[j - 1];

            ans[j] = nums[i];
            pos[j] = i;
        }
    }

    // print LIS
    vector<int> lis;
    int cur = pos.back();

    while(cur != -1)
    {
        lis.push_back(nums[cur]);
        cur = parent[cur];
    }

    reverse(lis.begin(), lis.end());

    cout << "LIS: ";
    for(int x : lis) cout << x << " ";
    cout << "\n";

    return ans.size();
}
};


int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    // Creating an object of Solution class
    Solution sol;
    int lengthOfLIS = sol.LIS(nums);
    
    cout << "The length of the LIS for the given array is: " << lengthOfLIS << endl;
    
    return 0;
}
