#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin>>n>>k;
    vector<long long>a(n);
    vector<long long>b(n);
    for (long long i = 0; i < n; i++) {
        cin>>a[i];
    }
    for (long long i = 0; i < n; i++) {
        cin>>b[i];
    }
    vector<pair<long long, long long>>s;
    long long count = 0;
    for(long long i = 0; i<n ;i++)
    {
        long long k = a[i]/b[i];
        count+=k;
        s.push_back({a[i]/b[i], i});
    }
    if(count<k)
    {
        for(long long i =0 ;i< n ;i++)cout<<0<<" ";
        cout<<endl;
        return 0;
    }
    long long extra = count - k;
    vector<long long>ans(n);
    for(long long i = 0;i<n ;i++)
    {
        if(extra>=0)
        {
            int skipped = min(extra, s[i].first);
            extra -= skipped;
            ans[i] = s[i].first-skipped;
        }
        else{
            ans[i] = s[i].first;
        }
    }
    for(long long i =0 ;i<n ;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}