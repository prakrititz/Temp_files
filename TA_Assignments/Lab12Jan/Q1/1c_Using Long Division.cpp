#include<bits/stdc++.h>
using namespace std;

#define int long long

string divideStringByTwo(string& number){
    string result;
    int remainder = 0;

    for(char c : number){
        // 1. Convert char digit to integer
        int digit = c - '0';
        
        // 2. Combine with remainder from previous step
        int value = remainder * 10 + digit;
        
        // 3. Calculate quotient digit and new remainder
        int quotient = value / 2;
        remainder = value % 2;
        
        // 4. Append quotient to result
        result.push_back(quotient + '0');
    }

    // 5. Remove leading zeros
    // We iterate until we reach the last character to ensure "0" is returned for input "0" or "1"
    reverse(result.begin(), result.end());
    while((int)result.size() > 1 && result.back() == '0'){
        result.pop_back();
    }
    reverse(result.begin(), result.end());
    return result;
}


int power(int x, string &n, int m){
    int res = 1;
    while(n != "0"){
        int idx = (int)n.size()-1;
        int lastDig = n[idx] - '0';
        if(lastDig%2){
            res = (res * x)%m;
        }
        x = (x * x)%m;
        n = divideStringByTwo(n);
    }
    return res;
}



int32_t main(){
    // Taking inputs
    int x, m;
    cin >> x;
    
    string n;
    // n cannot fit in int/long long, so taking it as a string
    cin >> n;

    cin >> m;

    // Here n is Decimal
    // So we can't simply iterate like we did in 1.(b)

    // Here we have to implement actual LONG DIVISION method
    int res = power(x, n, m);
    cout << res << endl;
}