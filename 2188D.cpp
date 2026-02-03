#include<bits/stdc++.h>
using namespace std;
#define int long long
int find(int a, int b)
{
    int inv = ~a;
    vector<int>ans={0};
    int cur = 0;
    for(int i = 60;i>=0;i--)
    {
        if(!(inv>>i&1))//has to be zero
        {
            if((b>>i)&1){//if its one   
                ans.push_back(cur | (inv)&((1LL<<i)-1));
                break;
            }
        }
        else{// is already zero i have two options
            if(!((b>>i) & 1)) {// if thats zero  
                 ans.push_back(cur|(1LL<<i));// just make remianing one and with inv
            } else {
                 ans.push_back(cur|(inv&((1LL<< i) - 1)));//put it one and remaing
                 cur |= (1LL << i);
            }
        }
        if (i == 0) ans.push_back(cur);   
    }
    int diff = LONG_LONG_MAX;
    int mini = 0;
    for(auto d:ans)
    {
        if(abs(b-d)<diff)
        {
            mini = d;
            diff = abs(b-d);
        }
    }
    return mini;
}

void solve()
{
    int x,y;
    cin>>x>>y;
    if((x&y)==0)
    {
        cout<<x<<" "<<y<<endl;
        return;
    }
    int q = find(x, y);
    int p = find(y, x);
    if(abs(y-q)<=abs(x-p))
    {
        // cout<<(x&q)<<endl;
        cout<<x<<" "<<q<<endl;
    }
    else{
        // cout<<(p&y)<<endl;
        cout<<p<<" "<<y<<endl;
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