#include<bits/stdc++.h>
using namespace std;
#define int long long
int majority(vector<int>&a)
{
    //The majority element is the element that appears more than ⌊n / 2⌋ times. 
    //Given that the majority element always exists in the array.
    int count = 0;
    int res  = -1;
    for(auto it: a)
    {
        if(count == 0)res = it;
        if(it==res)count+=1;
        else count-=1;
    }
    count = 0;
    for(auto it: a)
    {
        if(it==res)count++;
    }
    if(count>((a.size())/2))return res;
    return -1;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    cout<<majority(a)<<endl;    
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}