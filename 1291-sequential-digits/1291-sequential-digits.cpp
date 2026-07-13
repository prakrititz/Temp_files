class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int l = 0;
        int r = 0;
        vector<int>v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>>dp(9, vector<int>(9));
        vector<int>ans;
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                int num = 0;
                for(int k = i;k<=j;k++)
                {
                    num*=10;
                    num+=v[k];
                }
                dp[i][j] = num;
                if(num>=low && num<=high)ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
}; 