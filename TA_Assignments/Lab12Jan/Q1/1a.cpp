#include<bits/stdc++.h>
using namespace std;

// For safety, we take everything to be long long
#define int long long

// Binary Exponentiation
// Works in O(logn) [n -> the power to which the no. is raised]
int power(int x, int n, int m){
    int res = 1;
    while(n){
        if(n%2){
            res = (res*x)%m;
        } 
        x = (x*x)%m;
        n = n/2;
    }
    return res;
}

int32_t main(){
    // Taking Inputs
    int x, n, m;
    cin >> x >> n >> m;

    int res = power(x, n, m);
    cout << res << endl;
}