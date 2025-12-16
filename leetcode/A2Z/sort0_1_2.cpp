#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt = 0; int n = nums.size();
        int cnt2 = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0)cnt++;
            if(nums[i]==2)cnt2++;
        }
        int i = 0;
        int j = 0;
        while(i<cnt && j<n)
        {
            if(nums[j]==0){
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        for(int i = 0;i<n ;i++)cout<<nums[i]<<" ";
        cout<<endl;
        i = 0;
        j = n-1;
        while(i<cnt2 && j>=0)
        {
            if(nums[j]==2){
                swap(nums[n-1-i], nums[j]);
                i++;
            }
            j--;
        }
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