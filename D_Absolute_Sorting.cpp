#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;vector<int>a(n);
    int upper_limit = INT_MAX;
    int lower_limit = 0;
    for(int i =0 ;i<n ;i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n-1; i++) {
        if(a[i]<a[i+1])
        {
            upper_limit = min(abs(a[i]+a[i+1])/2, upper_limit);
        }
        else if(a[i]>a[i+1]){
            lower_limit = max(abs(a[i]+a[i+1]+1)/2, lower_limit);
        }
    }
    // cout<<upper_limit<<" "<<lower_limit<<endl;
    if(lower_limit>upper_limit)
    {
        cout<<-1<<endl;
    }
    else{
        cout<<lower_limit<<endl;
    }
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