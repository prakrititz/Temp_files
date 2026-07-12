class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long k = 1;
        while(k<n)k*=2;
        if(k==n)return true;
        return false;
    }
};