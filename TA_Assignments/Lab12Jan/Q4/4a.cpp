#include<bits/stdc++.h>
using namespace std;

#define int long long

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

        string noInString;
        if(no == 3) noInString = "11";
        else if(no == 2) noInString = "10";
        else if(no == 1) noInString = "1";
        else noInString = "0";
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

int32_t main(){
    string no1, no2;
    cin >> no1 >> no2;
    
    string no3 = add(no1, no2);
    cout << no3 << endl;
}