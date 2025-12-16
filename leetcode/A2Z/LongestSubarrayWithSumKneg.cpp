#include <bits/stdc++.h>
using namespace std;
//Problem Statement: Given an array nums of size n and an integer k, 
// find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
// a[i] can be negative too 
void solve() {
    int n, k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i = 0;i<n ;i ++)cin>>a[i];
    int cur_sum = 0;
    map<int ,int> mp;
    mp[0] = -1; // this is important 
    for(int i = 0;i<n ;i ++)
    {
        cur_sum += a[i];
        if (mp.find(cur_sum) == mp.end()) {
            mp[cur_sum] = i;
        }
    }
    cur_sum = 0;
    int len = 0;
    for(int j = 0;j<n;j++){   
    cur_sum += a[j];
        if(mp.find(cur_sum-k)!=mp.end())
        {
            int i = mp[cur_sum-k];
            len = max(len, j-i);
        }
    }
    cout<<len<<endl;

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