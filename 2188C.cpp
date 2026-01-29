#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool check(int k, int n, const vector<int>& a, const vector<int>&  x) {
    int mini = x.front();
    int maxi = x.back();
    if (maxi - mini < k) {
        for (int i = 0; i < n; i++) {
            if (a[i] != x[i]) return false;
        }
        return true;
    }
    int lower_bound = maxi - k;
    int upper_bound = mini + k;
    for (int i = 0; i < n; i++) {
        if (a[i] > lower_bound && a[i] < upper_bound) {
            if (a[i] != x[i]) {
                return false;
            }
        }
    }
    return true;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    map<int, int>mp;
    bool f = true;
    for(int i= 0;i<n ;i++){
        cin>>a[i];
        if(i!=0 && a[i]<a[i-1])
        {
            f = false;
        }
    }
    if(f){
        cout<<-1<<endl;
        return;
    }
    vector<int>x = a;
    sort(x.begin(), x.end());
    int l = 1;
    int r = 1e9;
    int ans = 1;
    while(l<=r)
    {
        int m = (l+r)/2;
        if(check(m, n, a, x))
        {
            ans = m;
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    cout<<ans<<endl;
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