#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i = 0 ;i< n ; i++)cin>>a[i];
        int i = 0;
        int count = 0;
        while(i<n)
        {
            if(a[i]%(i+2)!=0)
            {
                a[i]=0;
                count ++;
            }
            else{
                for(int j = 0 ; j<=count; j++)
                {
                    if(a[i]%(i+2-j)!=0)
                    {
                        count ++;
                        a[i] = 0;
                        break;
                    }
                }
            }
            i++;
        }
        bool flag = true;
        for(int i = 0; i<n ;i++)
        {
            if(a[i]!=0)flag = false;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}