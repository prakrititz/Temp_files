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
        for(int i = 0; i< n ;i++)
        {
            cin>>a[i];
        }
        int start = 0; 
        int end = n-1;
        while(start<n && a[start]==0)start++;
        while(end>=0 && a[end]==0)end--;
        if(start==n)cout<<0<<endl;
        else{
            bool c = false;
            for(int i = start ; i<= end ; i++)
            {
                if(a[i]==0)
                {
                    c = true;
                    break;
                }
            }
            if(c)
            {
                cout<<2<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
        
    }
    return 0;
}