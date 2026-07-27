class Solution {
public:
    int reverse(int x) {
        int ass = 0;
        while(x != 0){
            int digit = x % 10;

            if((ass > INT_MAX / 10) || (ass < INT_MIN / 10)){
                return 0;
            }

            ass = ass*10 + digit;

            x /= 10;
        }
        return ass;
    }
};