class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>dis(26, vector<int>(26, INT_MAX));
        for(int i = 0;i<original.size();i++)
        {
            char og = original[i];
            char ch = changed[i];
            dis[og-'a'][ch-'a'] = min(cost[i], dis[og-'a'][ch-'a']);
        }
        for(int i = 0;i<26;i++)dis[i][i]= 0;
        for(int k = 0;k<26;k++)
        {
            for(int i = 0;i<26;i++)
            {
                for(int j = 0;j<26;j++)
                {
                    if(dis[i][k] !=INT_MAX && dis[k][j]!= INT_MAX && dis[i][k]+ dis[k][j]< dis[i][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j]; 
                    }
                }
            }
        }
        long long ans  = 0;
        for(int i = 0;i<source.size();i++)
        {
            if(dis[source[i]-'a'][target[i]-'a']==INT_MAX)return -1;
            ans += dis[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};
