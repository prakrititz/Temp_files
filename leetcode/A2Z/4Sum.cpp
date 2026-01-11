#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<vector<int>> fourSum(vector<int>& a, int k) {
    int n = a.size();
    vector<vector<int>>ans;
    sort(a.begin(), a.end());
    for(int j = 0;j<n-3; j++)
    {
        while(j>0 && j<n-3 && a[j]==a[j-1])j++;
        for(int i = j+1;i<n-2;i++)
        {
            while(i>0 && i<n-2 && a[i]==a[i-1] && j+1!=i)i++;
            int l = i+1, r = n-1;
            int sum = 0;
            while(l<r && r>i)
            {
                sum = a[i]+a[r]+a[l]+a[j];
                if(sum==k)
                {
                    ans.push_back({a[i], a[l], a[r],a[j]});
                    int val1 = a[l];
                    int val2 = a[r];
                    while(l<n-1 && a[l]==val1)l++;
                    while(r>i && a[r]==val2)r--;
                }
                else if(sum>k)
                {
                    int val = a[r];
                    while(r>i && a[r]==val)r--;
                }
                else if(sum<k)
                {
                int val = a[l];
                while(l<n-1 && a[l]==val)l++;
                }
            }
        }
        
    }
    return ans;
}
void solve()
{
    int n, k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i= 0;i<n ;i++)cin>>a[i];
    vector<vector<int>>ans = fourSum(a, k);
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