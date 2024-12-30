#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;vector<int>a(n);
        for(int i =0; i< n ;i ++)cin>>a[i];
        for(int i = 0; i<n-1;i++)
        {
            if(a[i]>a[i+1] && abs(a[i]-a[i+1])==1)
            {
                swap(a[i], a[i+1]);
            }
        }
        bool flag = true;
        for(int i = 0; i<n-1; i++)
        {
            if(a[i]>a[i+1])flag = false;
        }
        if(flag)cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
        
    }
    return 0;
}