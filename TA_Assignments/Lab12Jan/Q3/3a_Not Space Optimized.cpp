#include<bits/stdc++.h>
using namespace std;

#define int long long

void multiply(string &answer, string &a, int n){
    int size = a.size();
    string carry = "0";
    for(int i = size-1; i>=0; i--){
        int curNo = a[i] - '0';
        int mul = curNo*n + stoll(carry);
        string no = to_string(mul);
        answer.push_back(no.back());
        
        carry = "0";
        int sizeOfNo = no.size();
        for(int j = 0; j<sizeOfNo-1; j++){
            carry.push_back(no[j]);
        }
    }

    reverse(answer.begin(), answer.end());
    answer = carry + answer;

    // Remove leading zeroes
    reverse(answer.begin(), answer.end());
    while((int)answer.size() > 1 && answer.back() == '0'){
        answer.pop_back();
    }
    reverse(answer.begin(), answer.end());
}

string add(string &a, string &b){
    int size1 = a.size(), size2 = b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // Just add zeros at the end to make the size equal
    if(size1 < size2){
        for(int i = size1; i<size2; i++){
            a.push_back('0');
        }
    }
    else if(size2 < size1){
        for(int i = size2; i<size1; i++){
            b.push_back('0');
        }
    }

    size1 = a.size(), size2 = b.size();

    string answer2 = "";
    string carry = "0";
    for(int i = 0; i<size1; i++){
        int no1 = a[i] - '0';
        int no2 = b[i] - '0';
        int no = no1 + no2 + stoll(carry);
        string noInString = to_string(no);
        answer2.push_back(noInString.back());
        int sizeOfNo = noInString.size();
        carry = "0";
        for(int j = 0; j<sizeOfNo-1; j++){
            carry.push_back(noInString[j]);
        }
    }

    reverse(answer2.begin(), answer2.end());
    answer2 = carry + answer2;

    // Remove leading zeroes
    reverse(answer2.begin(), answer2.end());
    while((int)answer2.size() > 1 && answer2.back() == '0'){
        answer2.pop_back();
    }
    reverse(answer2.begin(), answer2.end());

    return answer2;
}

string binToDec(vector<string> &powers, string &n){
    string answer = "";
    int size = n.size();
    for(int i = size-1; i>=0; i--){
        if(n[i] == '1'){
            answer = add(answer, powers[(size-1) - i]);
        }
    }
    return answer;
}

int32_t main(){
    string n;
    cin >> n;

    // We are storing powers of 2 beforehand till 10^5
    // NOTE: Stored in form of string
    vector<string> powers(1001, "");
    powers[0] = "1";
    for(int i = 1; i<1001; i++){
        multiply(powers[i], powers[i-1], 2);
        cout << "i = " << i << " = " << powers[i]  << endl;
    }
    
    string answer = binToDec(powers, n);
    cout << answer << endl;
}