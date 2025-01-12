#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        long long a, b, n, m;
        cin>>a>>b>>n>>m;
        if(n+m>a+b)cout<<"NO"<<endl;
        else {
        if(m>min(a, b))cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        }
    }   
    return 0;
}