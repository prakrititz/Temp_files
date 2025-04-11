#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int Dcnt = 0; 
    int Kcnt = 0;
    map<pair<int, int>, int>mp;//D:K
    vector<int>ans(n);
    for(int i = 0;i <n ; i++)
    {
        if(s[i]=='D')Dcnt++;
        if(s[i]=='K')Kcnt++;
        if(Dcnt==0 || Kcnt==0)
        {
            if(Kcnt==0)ans[i]= Dcnt;
            else ans[i] = Kcnt;
        }   
        int g = gcd(Dcnt, Kcnt);
        ans[i] = mp[{Dcnt/g, Kcnt/g}]+1;
        mp[{Dcnt/g, Kcnt/g}] = ans[i];
    }
    for(int i =0 ;i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}