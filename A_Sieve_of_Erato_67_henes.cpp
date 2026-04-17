#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
        int n;
        cin>>n;
        bool f = false;
        vector<int>a(n);
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==67)f = true;
        }
        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}