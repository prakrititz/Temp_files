#include <bits/stdc++.h>
using namespace std;

void solve() {
    
     int n;
     cin>>n;
     vector<int>a(n);
     for(int i =0 ;i <n; i++)cin>>a[i];
     for(int i =0; i<n-1;i++)
     {
        int x = min(a[i], a[i+1]);
        a[i+1]-=x;
        a[i]-=x;
     }
     bool check = true;
     for(int i =0 ;i < n-1; i++)
     {
        if(a[i]>a[i+1])check= false;
     }
     if(check)cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
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