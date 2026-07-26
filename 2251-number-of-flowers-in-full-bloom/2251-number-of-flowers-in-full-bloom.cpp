class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        for(auto it:flowers)
        {
            pq.push({it[0], 0, -1});
            pq.push({it[1], 2, -1});
        }
        for(int i = 0;i<people.size();i++)
        {
            pq.push({people[i], 1, i});
        }
        vector<int>ans(people.size());
        int cnt = 0;
        while(!pq.empty())
        {
            int x = pq.top()[0];
            int y = pq.top()[1];
            int z = pq.top()[2];
            pq.pop();
            if(y==0)
            {
                cnt++;
            }
            else if(y==1)
            {
                ans[z] = cnt;
            }
            else{
                cnt--;
            }
        }
        return ans;
    }
};