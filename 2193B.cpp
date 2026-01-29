#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>pos(n+1);
    for(int i = 0;i<n ;i++){
        cin>>a[i];pos[a[i]] = i;
    }
    int cur = n;
    int p = 0;
    while(cur)
    {
        if(pos[cur]==p){
            p++;
            cur--;
        }
        else{
            reverse(a.begin()+p, a.begin()+pos[cur]+1);
            break;
        }
    }
    for(auto it:a)cout<<it<<" ";
    cout<<endl;
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