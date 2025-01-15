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
        vector<int>b(n);
        for(int i = 0; i<n ;i++)cin>>a[i];
        for(int i = 0; i<n ;i++)cin>>b[i];
        bool g = true;
        for(int i = 0;i < n ; i++)
        {
            if(a[i]>b[i]){
                g = false;
                break;
            }
        }
        if(!g)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            bool gs = true;
            for(int i =0 ; i<n-1; i++)
            {
                if(a[i]!=b[i])
                {
                if(b[i]>b[i+1]+1){
                    gs = false;
                }
                }
            }
            if(b[n-1]!=a[n-1])
            {
            if(b[n-1]>b[0]+1){
                gs = false;
            }
            }
            if(gs)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}