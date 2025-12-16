#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while(j<nums.size())
        {
            if(nums[j]==0)j++;
            else
            {
                swap(nums[i], nums[j]);
                i++;j++;
            }
        }
        while(i<nums.size()){
            nums[i]=0;i++;}
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