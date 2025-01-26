#include <bits/stdc++.h>
using namespace std;

bool ifPrime(int n) {
    if(n<=1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    int k, upperBound = n/2;
    for(k = 3; k<=upperBound; k+=2) {
        upperBound = n/k;
        if(n%k==0) return false;
    }
    return true;
}

bool isPalindrome(int n) {
    int a[100];
    int i=0;
    while(n) {
        a[i]=n%10;
        n/=10;
        i++;
    }
    for(int j=0;j<i/2;j++) {
        if(a[j]!=a[i-j-1]) return false;
    }
    return true;
}

int main() {
    const int N = 1200000;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long u, v;
    cin >> u >> v;
    
    vector<int> prefixPalindrom(N);
    vector<int> prefixPrime(N);
    for(int i = 1; i < N; i++) {
        prefixPalindrom[i] = prefixPalindrom[i-1];
        prefixPrime[i] = prefixPrime[i-1];
        if(isPalindrome(i)) prefixPalindrom[i]++;
        if(ifPrime(i)) prefixPrime[i]++;
    }
    
    for(int i = N-1; i > 0; i--) {
        if(v * prefixPrime[i] <= u * prefixPalindrom[i]) {
            cout << i << endl;
            return 0;
        }
    }
    
    cout << "Palindromic tree is better than splay tree" << endl;
    return 0;
}
