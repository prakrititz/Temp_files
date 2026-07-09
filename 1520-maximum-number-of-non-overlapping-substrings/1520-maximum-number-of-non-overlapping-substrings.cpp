class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>>& intervals) {
    vector<vector<int>>again;
    sort(intervals.begin(), intervals.end(),
         [](const auto &a, const auto &b) {
             return a[1] < b[1];
         });

    vector<vector<int>> ans;
    int lastEnd = INT_MIN;

    for (auto &it : intervals) {
        if (it[0] > lastEnd) {
            ans.push_back(it);
            lastEnd = it[1];
        }
    }
    return ans;
}
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>>ivs;
        vector<int>first(26, -1);
        vector<int>last(26, -1);
        for(int i = 0;i<s.size();i++)
        {
            last[s[i]-'a'] = i;
            if((first[s[i]-'a']== -1))first[s[i]-'a'] = i;
        }

        set<vector<int>>f;
        
        for (int i = 0; i < 26; i++) {

            if (first[i] == -1)
                continue;

            int st = first[i];
            int en = last[i];

            bool ok = true;
            for (int j = st; j <= en; j++) {

                if (first[s[j] - 'a'] < st) {
                    ok = false;
                    break;
                }
                en = max(en, last[s[j] - 'a']);
            }

            if (ok)
                f.insert({st, en});
        }

        for(auto it:f)ivs.push_back(it);
        vector<vector<int>>temp = solve(ivs);
        vector<string>ans;
        for(auto it:temp)
        {
            ans.push_back(s.substr(it[0], it[1]-it[0]+1));
        }
        return ans;
    }
};