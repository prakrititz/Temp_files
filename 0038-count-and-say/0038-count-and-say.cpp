class Solution {
public:
    string temp(string curr){
        string s = "";
        int i = 0;
        while(i<curr.size())
        {
            int cnt = 1;
            int x = i;
            while(x<curr.size()-1 && curr[x]==curr[x+1])
            {
                cnt++;
                x++;
            }
            s+= to_string(cnt);
            s+= curr[i];
            i = x+1;
        }
        return s;
    }
    string countAndSay(int n) {
        string ans= "1";
        while(n-->1)ans = temp(ans);
        return ans;
    }
};