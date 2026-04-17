#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin() + 1, b.end());
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i++){
        int x = i;
        while(x % 2 == 0)
        {
            x = x / 2;
        }
        mp[x].push_back(i);
    }
    bool f = true;
    for(auto &it : mp)
    {
        vector<int> values;
        vector<int> target;
        for(int idx : it.second)
        {
            values.push_back(a[idx]);
            target.push_back(b[idx]);
        }
        sort(values.begin(), values.end());
        sort(target.begin(), target.end());
        if(values != target)
        {
            f = false;
            break;
        }
    }
    if(f)cout << "YES"<<endl;
    else cout << "NO"<<endl;
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