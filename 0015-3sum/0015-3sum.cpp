class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
    int n= a.size();
    sort(a.begin(), a.end());      
    vector<vector<int>>ans;
    for(int i = 0;i<n-2; i++)
    {
        while(i>0 && i<n-2 && a[i]==a[i-1])i++;
        int l = i+1, r = n-1;
        long long sum = 0;
        while(l<r && r>i)
        {
            sum = 1LL*(a[i]+a[r]+a[l]);
            if(sum==0)
            {
                ans.push_back({a[i], a[l], a[r]});
                int val1 = a[l];
                int val2 = a[r];
                while(l<n-1 && a[l]==val1)l++;
                while(r>i && a[r]==val2)r--;
            }
            else if(sum>0)
            {
                int val = a[r];
                while(r>i && a[r]==val)r--;
            }
            else if(sum<0)
            {
               int val = a[l];
               while(l<n-1 && a[l]==val)l++;
            }
        }
    }
    return ans;
    }
};