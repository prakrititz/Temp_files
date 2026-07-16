class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(((2+2*(n-1))*n)/2, (2*(n-1)*n)/2);
    }
};