class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while(i<nums.size())
        {
            while(i< nums.size() && nums[i]!=0)i++;
            int j = i+1;
            while(j<nums.size() && nums[j]==0)j++;
            if(j<nums.size() && i<nums.size())swap(nums[i], nums[j]);
            i++;
            j++;
        }
    }
};