class Solution {
public:
    long long gcdSum(vector<int>& A) {
        int max = 0;

        for (auto& n : A) {
            max = ::max(max, n);
            n = gcd(n, max);
        }
        sort(A.begin(), A.end());
        long long res = 0;
        for (int i = 0;i<A.size()/2;i++)
            res += gcd(A[i], A[A.size()-1-i]);
        return res;
    }
};