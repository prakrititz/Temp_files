#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b)
{
    if(a>b)return GCD(b, a);
    if(a==0|| a==b)return b;
    return GCD(b%a,a);
}

void solve() {
    long long a, b;
    cin>>a>>b;
    cout<<GCD(a, b)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}