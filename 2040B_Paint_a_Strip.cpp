#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        if(n==1)cout<<1<<endl;
        else{
            long long total_ones = 1;
            long long count = 1;
            while(total_ones<n)
            {
                total_ones  = (total_ones+1)*2;
                count ++;
            }
            cout<<count<<endl;
    }
    }
    return 0;

}