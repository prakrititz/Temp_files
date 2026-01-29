#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve() {
    int n;
    cin >> n;
    int m = 1;
    while(m<n)m*=2;
    if(m==n)
    {
        cout<<"-1"<<endl;
        return;
    }
    vector<int> p(n + 1);
    p[n] = 1;
    vector<bool> used(n + 1, false);
    used[1] = true;
    for (int i = 2; i < n; ++i) {
        p[i] = i ^ 1;
        used[p[i]] = true;
    }
    for (int v = 1; v <= n; ++v) {
        if (!used[v]) {
            p[1] = v;
            break;
        }
    }
    if(n%2==0)
    {
        int val = p[1];
        int x = 1;
        while(val%(2*x)==0)
        {
            x*=2;
        }
        swap(p[x], p[1]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << p[i] <<" ";
    }
    cout << endl;
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