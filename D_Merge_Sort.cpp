#include<bits/stdc++.h>
using namespace std;
#define int long long 
void unsort(vector<int>&a, int l, int r, int &k, int &cnt)
{
    if(k<=0)return;
    if(l<0)return;
    if (r - l <= 1) return;
    k-=2;
    int mid = (l+r)/2;
    swap(a[mid-1], a[mid]);
    unsort(a, l, mid,k, cnt);
    unsort(a, mid, r,k,cnt);
    
}
void solve()
{
    int n, k;
    cin>>n>>k;
    vector<int>a;
    for(int i = 1;i<=n;i++)a.push_back(i);
    if(k % 2 == 0 || k > 2*n - 1){
        cout << -1 << endl;
        return;
    }
    k--;
    int cnt = 0;
    unsort(a, 0, n, k,cnt);
    for(int i = 0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}