#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<vector<int>> threeSum(vector<int>& a) {
    int n= a.size();
    sort(a.begin(), a.end());      
    vector<vector<int>>ans;
    for(int i = 0;i<n-2; i++)
    {
        while(i>0 && i<n-2 && a[i]==a[i-1])i++;
        int l = i+1, r = n-1;
        int sum = 0;
        while(l<r && r>i)
        {
            sum = a[i]+a[r]+a[l];
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
void solve()
{   
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i= 0;i<n ;i++)cin>>a[i];
    vector<vector<int>>ans = threeSum(a);
    for(int i = 0;i<ans.size();i++)
    {
        for(auto it: ans[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}