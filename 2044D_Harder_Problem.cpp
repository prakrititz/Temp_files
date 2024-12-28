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
        for(int i =0 ; i<n ;i++)cin>>a[i];
        vector<int>ans(n, 0);
        vector<int>count(n);
        for(int i =0 ; i<n ;i++)
        {
            count[i] = i+1;
        }
        map<int, int>mp;
        for(int i =0 ;i<n;i++)
        {
            if(mp[a[i]]==0)
            {
                mp[a[i]]=1;
                ans[i] = a[i];
                count[a[i]-1] = -1;
            }
        }
        int i = 0; 
        int j  = 0;
        while(i<n)
        {
            while(count[j]==-1)j++;
            if(ans[i]==0)
            {
                ans[i]=count[j];
                j++;
            }
            i++;

        }
        for(int i = 0; i< n; i++)cout<<ans[i]<<" ";
        cout<<endl;

        
    }
    return 0;
}