#include<bits/stdc++.h>
#include <climits>
using namespace std;
int main(){
    long long tc;
    cin>>tc;
    while(tc--)
    {
        long long n;
        cin>>n;
        vector<long long>a(n);
        vector<long long>b(n);
        for(long long i = 0; i< n; i++)cin>>a[i];
        for(long long i =0; i< n; i++)cin>>b[i];
        long long ans = LLONG_MIN;
        for(int j = 0; j< n ; j++)
        {   long long sum = a[j]+b[j];
            for(long long i =0 ;i<n ;i++)
            {
                if(i!=j)
                {
                    sum+= max(a[i], b[i]);
                }
            }
            ans = max(sum, ans);
        }

        cout<<ans<<endl;
    }
    return 0;
}