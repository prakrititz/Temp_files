#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)

    {
        int n, k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i = 0; i< n ; i++)cin>>a[i];
        int ans = -1;
        for(int i = 0 ; i<n; i++)
        {
            bool notDiv = true;
            for(int j = 0; j< n; j++)
            {
                if(i!=j)
                {
                    int diff = abs(a[i]-a[j]);
                    if(diff%k==0)
                    {
                        notDiv = false;
                    }
                }
                if(j==n-1&&notDiv)
                {
                    ans = i+1;
                    break;
                }
            }
        }
        if(ans!=-1)
        {
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}