class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long num = 0;
        long long curr = 1;
        while(n)
        {
            if(n%10)
            {
                sum += n%10LL;
                num  = curr*(n%10) + num;
                curr*=10LL;
            }
            n/=10LL;
        }
        cout<<num<<endl;
        return sum*num;
    }
};