class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, queue<int>>mp;
        for(int i = 0;i<arr.size();i++)mp[arr[i]].push(i);
        vector<int>ans(arr.size());
        int cnt = 1;
        for(auto &it:mp)
        {
            while(!it.second.empty())
            {
                ans[it.second.front()] = cnt;
                it.second.pop();
            }
            cnt++;
        }
        return ans;
    }
};