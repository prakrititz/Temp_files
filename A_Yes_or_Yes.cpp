#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{ 
    string s;
    cin>>s;
    if(s.size()==1)
    {
        cout<<"YES"<<endl;
        return;
    }  
    if(s.size() == 2)
    {
        if(s!="YY")cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    vector<int>a;
    int cnt = 0;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]=='Y'){
            a.push_back(1);
            cnt++;
        }
        else 
        {
            if(a.size()!=0 && a.back()==0)continue;
            a.push_back(0);
        }
    }
    if(cnt<=1)
    {
        cout<<"YES"<<endl;
        return;
    }
    else {
        cout<<"NO"<<endl;
        return;
    }
    if(a.size()==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    if(a.size()==2)
    {
        if(a[0]==1 && a[1]==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
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