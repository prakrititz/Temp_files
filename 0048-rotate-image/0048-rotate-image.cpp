class Solution {
public:
void rotate(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        for(int j = 0;j<m; j++)
        {
            for(int i = j;i<n;i++)
            {
                swap(a[i][j], a[j][i]);
            }
        }
        for(int i = 0;i<n;i++)
        {
            reverse(a[i].begin() ,a[i].end());
        }
}
};