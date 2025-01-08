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
        vector<long long >a(n);
        map<long long , long long >mp;
        for(long long  i = 0; i< n ;i++){
            cin>>a[i]; 
            mp[a[i]]++;

        }
    long long  count = 0; 
    for(long long  i = 0; i<n ;i++)
    {
        if(a[i]==2 || a[i]==1)
        {
            long long  total = mp[1]+mp[2];
            count += (total*(total-1))/2;
            mp[1] = 0;
            mp[2] = 0;

        }
        else
        {
            count += (mp[a[i]]*(mp[a[i]]-1))/2;
            mp[a[i]]=0;
        }
        
    }
    cout<<count<<endl;
    }
    return 0;
}