#include <bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int t;
cin >> t;
while(t--){
    int n;
    cin >> n;
    map<int, int>marked;
    vector<int> ans(n);
    for(int i = 0; i<n ;i++)
    {
        ans[i] = i+1;
    }
    ans[n-1] = 1;
    ans[1] = 1;
    for (int i = 0; i < n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
    return 0;
}
