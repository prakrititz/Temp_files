#include<bits/stdc++.h>
using namespace std;
int  main()
{
    long long  tc;
    cin>>tc;
    while(tc--)
    {
        long long  n;
        cin>>n;
        long long  sum = 0;
        vector<long long >a(n);
        for(long long  i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%n==0)
        {
            long long  val = sum/n;
            for(long long  i = 0; i<=n-3;i++)
            {
                if(a[i]>val)
                {
                    a[i+2] += a[i]-val;
                    a[i] = val;
                }
                else{
                    a[i+2] -= val-a[i];
                    a[i] = val;
                }
            }
            bool s = true;
            for(long long  i = 0; i<n; i++)
            {
                if(a[i]!=val)
                {
                    s = false;
                    break;
                }
            }
            if(s)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else
        {
            cout<<"NO"<<endl;

        }
    }
    return 0;
}