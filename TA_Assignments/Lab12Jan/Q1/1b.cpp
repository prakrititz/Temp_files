#include<bits/stdc++.h>
using namespace std;

#define int long long

// The logic is same (just think how it can be done using binary nos.)

// Ex - Binary no. -  100110101
// 100110101 - ODD as last bit is '1'
//      dividing by 2 -> 10011010
// 10011010 (after dividing by 2) - EVEN as last bit is '0'
// ... so on

int power(int x, string &n, int m){
    int res = 1;
    int size = n.size();
    // Instead of actually dividing, just iterate from right to left
    for(int i = size-1; i>=0; i--){
        // Means currently it is odd
        if(n[i] == '1'){
            res = (res * x)%m;
        }
        x = (x*x)%m;
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

    int res = power(x, n, m);
    cout << res << endl;
}