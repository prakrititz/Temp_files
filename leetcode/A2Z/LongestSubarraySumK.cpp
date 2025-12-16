#include <bits/stdc++.h>
using namespace std;
//Problem Statement: Given an array nums of size n and an integer k, 
// find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i = 0;i<n ;i ++)cin>>a[i];
    int i = 0;
    int cur_sum = 0;
    int len = 0;
    for(int j = 0;j<n;j++)
    {   cur_sum += a[j];
        while (cur_sum > k) {
            cur_sum -= a[i];
            i++;
        }
        if(cur_sum==k)
        {
            len = max(len, j-i+1);
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