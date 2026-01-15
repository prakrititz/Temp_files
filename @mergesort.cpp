#include<bits/stdc++.h>
using namespace std;
#define int long long 
void merge(vector<int>&a,int l1, int r1, int l2, int r2, int n)
{
    int i = l1;
    int j = l2;
    vector<int>temp;
    while(i<=r1 && j<=r2)
    {
        if(a[i]>a[j]){
            temp.push_back(a[j]);
            j++;
        }
        else {
            temp.push_back(a[i]);
            i++;
        }
    }
    while(i<=r1)
    {
        temp.push_back(a[i]);
        i++;
    }
    while(j<=r2)
    {
        temp.push_back(a[j]);
        j++;
    }
    for(int i = l1;i<=r2;i++)a[i] = temp[i-l1];
}
void merge_sort(vector<int>&a, int l, int r, int n)
{
    if(l<0)return;
    if(r>n-1)return;
    if(l>=r)return;
    int mid = (l+r)/2;
    merge_sort(a, l, mid, n);
    merge_sort(a, mid+1, r, n);
    merge(a, l, mid, mid+1, r, n);
}
void solve()
{  
    int n;cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n;i++)cin>>a[i]; 
    merge_sort(a, 0, n-1, n);
    for(auto it:a)cout<<it<<" ";
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