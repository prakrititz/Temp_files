#include<bits/stdc++.h>
using namespace std;

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int diff = 0;
        for(int i = 0; i<n; i++){
            if(s[i] != t[i]) diff++;
        }
        
        if(diff > 2){
            cout << 0 << endl;
            continue;
        }
        if(!diff){
            cout << (n+1)*26 << endl;
            continue;
        }

    }
}