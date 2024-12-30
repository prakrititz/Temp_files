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
        vector<int>cnt(n+1);
        for(int i =0 ;i < n ; i++)
        {
            cin>>a[i];
            cnt[a[i]]++;
        }
        int maxi = INT_MIN;
        for(int i =1 ; i< n+1; i++)
        {
            maxi = max(maxi, cnt[i]);
        }
        int ans = n-maxi;
        cout<<ans<<endl;
    }
    return 0;
}