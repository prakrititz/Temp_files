#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n, a, b;
        cin>>n>>a>>b;
        vector<int>arr(n);
        for(int i =0 ;i<n; i++)cin>>arr[i];
        int k = gcd(a, b);
        vector<int>ls(n);
        for(int i =0; i<n; i++)
        {
            ls[i] = arr[i]%k;
        }    
        sort(ls.begin(), ls.end());
        int mini  = ls[n-1]-ls[0];
        for(int i =1 ;i < n; i++)
        {
            mini = min(mini, ls[i-1]+k-ls[i]);
        }
        cout<<mini<<endl;
    }
    return 0;
}