#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        long long n;
        cin>>n;
        int count = 1;
        while(n>=3)
        {
            n/=4;
            count*=2;
        }
        cout<<count<<endl;
    }
}