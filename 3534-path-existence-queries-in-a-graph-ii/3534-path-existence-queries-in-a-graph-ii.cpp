class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>v;
        for(int i =0;i<n ;i++){
            v.push_back(nums[i]);
        }
        int LOG = 18;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        vector<vector<int>>dp(v.size(), vector<int>(LOG));
        for(int i = 0;i<v.size();i++)
        {
            dp[i][0] = (int)(upper_bound(v.begin(), v.end(), maxDiff+v[i])-v.begin())-1;
        }
        for(int i = 1;i<LOG;i++)
        {
            for(int j = 0;j<v.size();j++)
            {
                dp[j][i] = dp[dp[j][i-1]][i-1];
            }
        }
        vector<int>ans;
        for(auto it:queries)
        {
            int u = nums[it[0]];
            int target = nums[it[1]];
            if(it[0]==it[1]){
                ans.push_back(0);continue;
            }
            if(u==target){
                ans.push_back(1);continue;
            }
            if(u>target)swap(u, target);
            int cnt = 0;
            int curr = lower_bound(v.begin(), v.end(), u)-v.begin();
            int final = lower_bound(v.begin(), v.end(), target)-v.begin();
            if(dp[curr][LOG-1]<final){
                ans.push_back(-1);
                continue;
            }
            for(int i = LOG-1;i>=0;i--)
            {
                if(dp[curr][i]<final){
                    curr = dp[curr][i];
                    cnt += (1<<i);
                }
            }
            ans.push_back(cnt+1);
        }
        return ans;
    }
};