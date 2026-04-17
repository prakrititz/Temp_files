#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>x = {1, 2, 3, 4, 5, 6};
    for(int i =0;i<n;i++)cin>>a[i];
    int cnt = 0;
    if(n==2)
    {
        if(a[0]+a[1]==7|| a[0]==a[1])cout<<1<<endl;
        else cout<<0<<endl;
        return ;
    }
    for(int i = 0;i<n-1;i++)
    {
        int mid = a[i+1];
        if(i<n-2)
        {
            if(a[i]+a[i+1]==7 || a[i]==a[i+1])
            {
                for(auto it:x)
                {
                    if(it+a[i]!=7 && it+a[i+2]!=7 && it!=a[i] && it!=a[i+2])
                    {
                        a[i+1] = it;
                        cnt++;
                        break;
                    }
                }
            }
        }
        else{
            if(a[i]+a[i+1]==7 || a[i]==a[i+1])
            {
                for(auto it:x)
                {
                    if(it+a[i]!=7 && it!=a[i])
                    {
                        a[i+1] = it;
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
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