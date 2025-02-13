#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m;
    cin>>n>>m;
    long long temp = n;
    long long two = 0; long long five = 0;
    while(temp%2==0)
    {
        temp/=2;
        two++;
    }
    while(temp%5==0)
    {
        temp/=5;
        five++;
    }
    long long ans = 1;
    if(two>five)
    {
        for(long long i = 1;i <= two-five && ans*5<=m ; i++)
        {
            ans*=5;
        }
    }
    else
    {
        for(long long i = 1;i <= five-two && ans*2<=m ; i++)
        {
            ans*=2;
        }
    }
    while(ans*10<=m)
    {
        ans*=10;
    }
    cout<<n*(m/ans)*ans<<endl;
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