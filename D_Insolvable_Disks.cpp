#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i =0;i<n;i++)cin>>a[i];
    int ans = 0;
        if(n==1){
        cout<<0<<endl;
        return;
    }
    if(n==2)
    {
        cout<<1<<endl;
        return;
    }
    map<pair<int, int>, int>mp;
    for(int i = 1;i<n-1;i++)
    {
        int left = a[i]-a[i-1];
        int right = a[i+1]-a[i];
        if(left==right){
            if(mp.find({a[i-1],a[i]})==mp.end()){
                ans++;
                mp[{a[i-1],a[i]}]++;
            }
            if(mp.find({a[i],a[i+1]})==mp.end()){
                ans++;
                mp[{a[i],a[i+1]}]++;
            }
        }
        else if(left>right)
        {
            if(mp.find({a[i],a[i+1]})==mp.end()){
                ans++;
                mp[{a[i],a[i+1]}]++;
            }
            if(i==1)
            {   
                ans++;
            }
        }
        else if(right>left)
        {
            if(mp.find({a[i-1],a[i]})==mp.end()){
                ans++;
                mp[{a[i-1],a[i]}]++;
            }
            if(i==n-2)
            {   
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}