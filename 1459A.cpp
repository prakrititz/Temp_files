#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    int n;
    cin>>n;
    string a;
    string b;
    cin>>a>>b;
    int x =0, y= 0;
    for(int i =0;i<n;i++){
        if(a[i]>b[i]){
            x++;
        }
        else if(b[i]>a[i]){
            y++;
        }
    }
    if(x==y)cout<<"EQUAL"<<endl;
    else if(x>y)cout<<"RED"<<endl;
    else cout<<"BLUE"<<endl;
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