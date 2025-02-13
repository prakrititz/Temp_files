#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin>>n;
    vector<long long>a(n);
    vector<long long>A;
    vector<long long>B;
    map<long long, long long>distA;
    map<long long, long long>distB;
    long long count = 0;
    map<long long,long long>mp;
    vector<long long>b(n);
    for(long long i = 0; i<n ; i++)
    {
        cin>>a[i];
        if(distA[a[i]]==0)
        {
            distA[a[i]]++;
            A.push_back(a[i]);
        }
    }
    for(long long i =0 ;i<n ;i++)
    {
        cin>>b[i];
        if(distB[b[i]]==0)
        {
            distB[b[i]]++;
            B.push_back(b[i]);
        }
    }
    for(long long i = 0;i<A.size(); i++)
    {
        for(long long j = 0; j<B.size();j++)
        {
            if(mp[A[i]+B[j]]==0)
                {
                    count++;
                    mp[A[i]+B[i]]++;
                }
        }
    }
    if(count>=3)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}