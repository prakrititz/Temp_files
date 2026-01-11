#include<bits/stdc++.h>
using namespace std;

#define int long long

int getMod(string &x, int m){
    int res = 0;
    int size = x.size();
    for(int i = 0; i<size; i++){
        res = (res*10 + (x[i]-'0'))%m;
    }   
    return res;
}

int32_t main(){
    string x;
    cin >> x;

    int m;
    cin >> m;

    int res = getMod(x, m);
    cout << res << endl;
}