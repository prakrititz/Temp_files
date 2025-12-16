#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int j = -1;
        for(int i = 0;i<n-1 ;i ++)
        {
            if(nums[i]>nums[i+1]){
                cnt++;
                j = i+1;
            }
        }
        // THIS DIP WILL GIVE ME THE CORRECT POSITION OF MIN (IN CASE OF DUPLICATE MINIMUMS)
        cout<<j<<endl;
        if(cnt==1){        
            for(int i = 0;i<n-1; i ++)
            {
                int k = (i+j)%n;
                int p = (k+1)%n;
                cout<<k<<" "<<p<<endl;
                if(nums[k]>nums[p])cnt++;
            }
        }
        // FROM CORRECT PLACE OF MINIMUM I CAN DO CYCLIC CHECK
        if(cnt>1)return false;
        else return true;
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