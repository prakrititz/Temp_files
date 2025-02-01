#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    string s;
    cin>>s;
    long long cnt = 0;
    for(long long i= 0;i < n; i++){
        if(s[i]=='1')cnt++;
    }
    for( long long i = pow(2, cnt); i<= pow(2, n)-(pow(2, n-cnt)-1); i++)cout<<i<<" ";
    cout<<endl;
    return 0;
}