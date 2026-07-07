class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for(auto it:nums)
        {
            g = gcd(it, g);
            if(g==1)return true;
        }
        return false;
    }
};