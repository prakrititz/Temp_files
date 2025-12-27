#include<bits/stdc++.h>
using namespace std;
#define int long long 
void nextPermutation(vector<int>&a)
{
    int n; n = a.size();
    int j = -1;
    for(int i = n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {
            j = i;
            break;
        }
    }
    if(j==-1){
        reverse(a.begin(), a.end());
        return;
    }
    for(int i = n-1;i>j;i--)
    {
        if(a[i]>a[j])
        {
            swap(a[i], a[j]);
            break;
        }
    }
    reverse(a.begin()+j+1, a.end());
}
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    nextPermutation(a);
    for(int i =0;i<n;i++)cout<<a[i];   
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