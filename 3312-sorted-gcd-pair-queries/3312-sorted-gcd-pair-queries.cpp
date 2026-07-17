class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = *max_element(nums.begin(), nums.end());
        vector<long long> freq(m + 1, 0), exact_gcd(m + 1, 0);
        for (int num : nums) freq[num]++;
        for (int i = m; i >= 1; i--) {
            long long c = 0;
            for (int j = i; j <= m; j += i) c += freq[j];
            exact_gcd[i] = (c * (c - 1)) / 2;
            for (int j = 2 * i; j <= m; j += i) {
                exact_gcd[i] -= exact_gcd[j];
            }
        }
        vector<int> ans(queries.size());
        vector<pair<long long, int>> v;
        for(int i = 0; i < queries.size(); i++) v.push_back({queries[i], i}); 
        sort(v.begin(), v.end());
        int i = 0;
        long long cnt = 0;
        for(int g = 1; g <= m; g++)
        {
            long long t = exact_gcd[g];
            while(i < v.size() && cnt + t > v[i].first)     
            {
                ans[v[i].second] = g;
                i++;
            }
            cnt += t;
        }
        return ans;
    }
};