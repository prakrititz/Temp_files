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


string decToBin(string &n){
    string res = "";
    while(n != "0"){
        int idx = (int)n.size()-1;
        int lastDig = n[idx] - '0';
        if(lastDig%2){
            res.push_back('1');
        }
        else{
            res.push_back('0');
        }
        n = divideStringByTwo(n);
    }
    reverse(res.begin(), res.end());
    return res;
}


int32_t main(){
    string n;
    cin >> n;
    string bin = decToBin(n);
    cout << bin << endl;
}