#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k;
    cin>>n>>k;
    vector<long long>a(n);   
    vector<pair<long long, long long>>mp;
    for(long long i = 0; i<n; i++)cin>>a[i];
    for(long long i= 0; i<n ;i ++){
        mp.push_back({-a[i], i});}
    vector<long long>result;
    long long ans = 0; 
    sort(mp.begin(), mp.end());
    for(long long i =0 ;i <k; i++)
    {
        result.push_back(mp[i].second);
        ans += mp[i].first;
    }
    sort(result.begin(), result.end());
    cout<<abs(ans)<<endl; long long cur = 0;
    for(long long i =0; i<result.size()-1; i++){
        cout<<result[i]-cur+1<<" ";
        cur = result[i]+1;
    }
    cout<<n-cur<<endl;


    
}