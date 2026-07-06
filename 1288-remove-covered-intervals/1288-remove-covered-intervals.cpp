class Solution {
public:
    static bool comp(vector<int>a, vector<int>b){
        if(a[0]==b[0])return a[1]>b[1];
        else return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n =intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int s = intervals[0][0];
        int e =intervals[0][1];
        int cnt = 0;
        for(int i = 1;i<n;i++)
        {
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            if(ce<=e)
            {
                cnt ++;
            }
            else{
                s = cs;
                e = ce;
            }
        }
        return n-cnt;
    }
};