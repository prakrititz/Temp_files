#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i = 0;i<n; i++)cin>>a[i];
    vector<pair<int , int>>v;
    map<int, int>mp;
    for(int i = 0;i<n ;i++)
    {
        if(mp.find(a[i])==mp.end())
        {
            v.push_back({i, a[i]});
        }
        mp[a[i]]++;
    }
    int x = v.size();
    if(v.size()==1)
    {
        cout<<min(a[0], k)*n<<endl;
        return;
    }
    vector<vector<int>>dp1(k+1, vector<int>(k+1, INT_MIN));
    vector<vector<int>>dp2(k+1, vector<int>(k+1, INT_MIN));
    vector<vector<vector<int>>>pre(x, vector<vector<int>>(k+1, vector<int>(k+1, INT_MIN)));
    // need to initialize for 0 dp[0][value][sum];
    for(int i = 0;i<=a[0];i++)
    {
        dp1[i][i] =  i*(v[1].first-v[0].first);
    }
    // need to initlaize for pre[0][value][sum];
    for(int j = 0;j<=k;j++)
    {
        pre[0][0][j] = dp1[0][j];
        for(int i = 1;i <= k; i++){
            pre[0][i][j] = max(dp1[i][j], pre[0][i-1][j]);
        }
    }
    for(int i = 1;i<v.size();i++)
    {
        dp2 = dp1;
        int count;
        if(i  == v.size()-1){
            count = n - v[i].first;
        }
        else 
        {
            count = v[i+1].first - v[i].first;
        }
        for(int j = 0;j<=k;j++)
        {
            for(int val = 0;val<=v[i].second && val+j<=k;val++)
            {
                dp2[val][j+val] = max(dp2[val][j+val], val*(count) + pre[i-1][val][j]);  
            }
            for(int val = 0; val<=k ; val++)
            {
                dp2[val][j] = max(dp2[val][j], dp1[val][j] + val*count);
            }
        }
        for(int j = 0; j <= k; j++) {
            pre[i][0][j] = dp2[0][j];
            for(int l = 1; l <= k; l++) {
                pre[i][l][j] = max(dp2[l][j], pre[i][l-1][j]);
            }
        }
        dp1 = dp2;
    }
    cout << *max_element(pre.back().back().begin(), pre.back().back().end())<<endl;
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