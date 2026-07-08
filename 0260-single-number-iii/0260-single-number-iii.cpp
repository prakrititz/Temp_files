class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto it:nums)ans ^= it;
        int x = 0;
        while(!(ans&1))
        {
            ans/=2;
            x++;
        }
        int r = 0;
        int l = 0;
        for(auto it:nums)
        {
            if(it&(1<<x))l^=it;
            else r^=it;
        }
        return {l, r};
    }
};