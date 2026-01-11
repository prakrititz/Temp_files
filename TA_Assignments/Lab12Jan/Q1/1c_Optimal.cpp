#include<bits/stdc++.h>
using namespace std;

#define int long long

int power(int x, string &n, int m){
    int res = 1;
    for(int i = (int)n.size()-1; i >= 0; i--){
        int dig = (n[i] - '0');
        for(int j = 0; j<dig; j++){
            res = (res * x)%m;
        }
        int z = (x * x)%m;
        x = (z * z)%m;
        x = (x * x)%m;
        x = (z * x)%m;
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