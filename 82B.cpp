#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;
    cin>>n;

    map<int, vector<int>>mp;
    vector<set<int>>s;
    vector<set<int>>a;
    int total = (n*(n-1))/2;
    if(n==2)
    {
        int k;
        cin>>k;
        vector<int>temp;
        while(k--)
        {
            int a;
            cin>>a;
            temp.push_back(a);
        }
        cout<<1<<" "<<temp[0]<<endl;
        cout<<temp.size()-1<<" ";
        for(int i = 1;i<temp.size();i++)cout<<temp[i]<<" ";
        return;
    }
    for(int i = 0;i<total;i++)
    {
        int k;
        cin>>k;
        set<int>temp;
        while(k--){
            int x;
            cin>>x;
            mp[x].push_back(i);
        }
    }
    map<vector<int>,vector<int>>mp2;
    for(auto it:mp){
        mp2[it.second].push_back(it.first);
    }
    for(auto it: mp2)
    {
        cout<<it.second.size()<<" ";
        for(auto p: it.second)cout<<p<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}