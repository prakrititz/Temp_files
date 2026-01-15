#include<bits/stdc++.h>
using namespace std;
#define int long long  // This will rename all int to long long if this line is not used all int must be replaced with long long or long long int
// Background
int pow_straightForward(int x, int n){
    int ans = 1;// straight forward how we would write
    while(n--)
    {
        ans *= x;
    }
    return ans;
}
int pow_recursive(int x, int n) //bad in stack space 
{
    // Idea is to take the power in form of recusion;
    //base case
    if(n==0)return 1;
    if(n==1)return x;
    //recursion
    if(n%2)return pow_recursive(x, n/2)*pow_recursive(x, n/2)*x;
    else return pow_recursive(x, n/2)*pow_recursive(x, n/2);
    //T(n) = 2*T(n/2)+O(1) overall T(N) = O(N);
}
int pow_BinExponential(int x, int n) {
    // Idea is n can be represented as a binary number.
    // take an example n = 57.
    // 57 in binary is 111001b
    // This equals: 2^5 + 2^4 + 2^3 + 0 + 0 + 2^0
    // So x^57 = x^(32) * x^(16) * x^(8) * x^(1)
    
    int ans = 1; 
    while (n > 0) {        
        // Check if (n%2 != 0)
        // If the bit is 1, we include the current power of x in our answer.
        if (n % 2 != 0) {
            ans = ans * x; 
        }
        // Prepare the next power of x regardless of whether the bit was 0 or 1, we square x.
        // this calculates x^1, then x^2, then x^4, then x^8...
        x = x * x; 
    
        // We move to the next bit and discard the LSB we just processed.
        n = n / 2; 
    }
    
    return ans;
    //T(N) = O(log N)
}

//Now for the questions:
// 1. Given x, n, m, 2 ≤x ≤1e9, 2 ≤m ≤1e6 find x^n(mod m).
// a. n < 1e18
int pow_sol_a(int x, int n, int m)
{
    // This big number wont even fit in long long so we m to take care of 
    // we will simply do Binary Exponentiation but keep taking mod every time we do 
    int ans = 1; 
    while (n > 0) {        
        // Check if (n%2 != 0)
        // If the bit is 1, we include the current power of x in our answer.
        // Take Mod m every time we do so;
        if (n % 2 != 0) {
            ans = (ans * x)%m; 
        }
        // Prepare the next power of x regardless of whether the bit was 0 or 1, we square x.
        // this calculates x^1, then x^2, then x^4, then x^8...
        x = (x * x)%m; 
    
        // We move to the next bit and discard the LSB we just processed.
        n = n / 2; 
    }
    return ans;
    //T(N) = O(log N)
}

//b. n < 2^(1e5), given in binary
// Input must be in form of string since its binary
int pow_sol_b(int x, string n, int m)
{
    int ans = 1;
    // goint to do the same but this time we will just take the a pointer and keep moving left
    int i = n.size()-1;
    while(i>=0)
    {
        if(n[i]=='1'){
            ans = (ans*x)%m;
        }
        x = (x*x)%m;
        i--; // since this is a string, basically doing the same
    }
}

string temp(string &n){
        string res = "";
        int rem = 0;
        for(int i = 0;i<n.size();i++)
        {
            int digit = n[i]-'0';//this is the digit;
            int val = rem*10+digit;
            int quotient = val/2;
            rem = val%2;
            // initally we add only when result is empty and quotient is not zero 
            if(res=="" && quotient==0){
                continue;
            }
            res += quotient+'0';
        }
        if(res=="")res = "0";
        n = res;// modify the n
        return res;// return the remainder 
}
//c. n < 10^1e5, given in decimal.
// this big number has to be given in string as input
int pow_sol_c(int x, string &n, int m)
{
    // To calculate in log(n) we will need to figure out how to divide a "String Decimal Number by 2" and get the remainder
    // If we figure out that we can simply similarly write a function similar to binary exponentiation
    // We can divide in traditional long division that we did in school.
    auto func = [](string &n)->int{
        string res = "";
        int rem = 0;
        for(int i = 0;i<n.size();i++)
        {
            int digit = n[i]-'0';//this is the digit;
            int val = rem*10+digit;
            int quotient = val/2;
            rem = val%2;
            // initally we add only when result is empty and quotient is not zero 
            if(res=="" || quotient!=0){
                res += quotient+'0';
            }
        }
        if(res=="")res = "0";
        n = res;// modify the n
        return rem;// return the remainder 
    };
    string hb = "11435";
    cout<<temp(hb)<<endl;
    int ans = 1;
    while(n!="0")
    {
        if(func(n)==1)ans = (ans*x)%m;
        x = (x*x)%m;
    }
    return ans;
    //T(N)  = O(len(N) * log X) can we do better?  Yes
} 

int pow_sol_c_better(int x, string &n, int m) {
    int res = 1;
    int base = x; 
    // forget binary, let's think in standard Base-10 (Decimal).
    // x^235 = (x^200) * (x^30) * (x^5)
    // if we process digits from right to left (units -> tens -> hundreds).
    
    for (int i = n.size() - 1; i >= 0; i--) {
        // first we multiply the current base 'digit' times
        // if digit is 5, we multiply result by base^5
        for (int j = 0; j < n[i] - '0'; j++) {
            res = (res * base) % m;
        }
        // power up the base for the next position
        // if current base is x. Next loop needs x^10. 
        // then x^100, then x^1000...
        
        // we can calculate base^10 manually using squaring:
        // base^10 = (base^2 * base^8)
        int z = (base * base) % m; // base^2
        int y = (z * z) % m;       // base^4
        y = (y * y) % m;                 // base^8
        base = (y * z) % m;              // base^8 * base^2 = base^10
    }
    return (int)res;
    //T(N)  = O(len(N)*9); Good;
} 

void solve()
{   

    int n; string s;int m; // 3 57 100

    cin>>n>>s>>m;
    cout<<pow_sol_c_better(n, s, m)<<endl;
    cout<<pow_sol_c(n, s, m)<<endl;
    // cout<<pow_sol_a(n, s, m)<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}