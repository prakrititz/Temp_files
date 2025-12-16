#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rev(vector<int>&a, int l, int r)
    {
        while(l<r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        rev(nums, 0, nums.size()-1);
        rev(nums, 0, k-1);
        rev(nums, k, nums.size()-1);

    }
};
void solve();
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