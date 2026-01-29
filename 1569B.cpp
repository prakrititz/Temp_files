#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string>v;
    int cnt = 0;
    int cnt2 = 0;
    for(int i = 0;i<n;i++)
    {
        string temp = "";
        if(s[i]=='1')cnt++;
        else cnt2 ++;
        for(int j = 0;j<n;j++)
        {
            if(j!=i)temp+="=";
            else temp+="X";
        }
        v.push_back(temp);
    }
    if(cnt2==1|| s=="22"){
        cout<<"NO"<<endl;
        return;
    }
    else{

        for(int i = 0;i<n;i++)
        {
            if(s[i]=='2')
            {
                for(int j = 0;j<n;j++)
                {
                    if(v[i][j]=='=' && s[j]!='1'){
                        v[i][j] = '+';
                        v[j][i] = '-';
                        break;
                    }
                }
                int x = 0;
                for(int j= 0;j<n;j++)
                {
                    if(v[i][j]=='+'){
                        x++;
                    }
                }
                if(x==0)
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
        cout<<"YES"<<endl;
        for(auto s: v)cout<<s<<endl;
    }

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