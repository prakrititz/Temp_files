#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> majorityElement(vector<int>& a) {
        int n = a.size();   
        int c1 = 0;
        int c2 = 0;
        int e1 = INT_MAX;
        if(n==1){
            return {a[0]};
        }
        int e2 = INT_MAX;
        for(int i = 0;i<n; i++)
        {
            if(c1==0 && a[i]!=e2)
            {
                c1 = 1;
                e1 = a[i];
            }
            else if(c2==0 && a[i]!=e1){
                c2 = 1;
                e2 = a[i];
            }
            else if(a[i]==e1)c1++;
            else if(a[i]==e2)c2++;
            else{
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for(int i = 0;i<n; i++)
        {
            if(a[i]==e1)c1++;
            else if(a[i]==e2)c2++;
        }
        vector<int>ans;
        if(c1>n/3)ans.push_back(e1);
        if(c2>n/3)ans.push_back(e2);
        return ans;
}
void solve()
{ 
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n ;i ++)cin>>a[i];
    vector<int> ans = majorityElement(a);
    for(int i = 0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;
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