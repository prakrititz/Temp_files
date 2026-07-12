class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        if(nums.size()==2)
        {
            if(nums[0]>nums[1])return 0;
            else return 1;
        }
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(m<nums.size()-1 && nums[m]<nums[m+1])
            {
                l = m+1;
            }
            else if(m>0 &&  nums[m-1]>=nums[m])
            {
                r = m-1;
            }
            else return m;
        }
        return -1;        
    }
};