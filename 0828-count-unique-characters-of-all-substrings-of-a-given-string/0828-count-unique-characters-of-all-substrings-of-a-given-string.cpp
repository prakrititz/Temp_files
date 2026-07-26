class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> prevSeen(26, -1);
        vector<int> lastSeen(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            if (lastSeen[c] != -1) {
                ans += (lastSeen[c] - prevSeen[c]) * (i - lastSeen[c]);
            }
            prevSeen[c] = lastSeen[c];
            lastSeen[c] = i;
        }
        for (int c = 0; c < 26; c++) {
            if (lastSeen[c] != -1) {
                ans += (lastSeen[c] - prevSeen[c]) * (n - lastSeen[c]);
            }
        }
        
        return ans;
    }
};