#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    int n;
    cin>>n;
    vector<string>s(n);
    vector<string>sr(n);
    for(int i = 0;i<n;i++){
        cin>>s[i]; sr[i] = s[i];
    }
    sort(sr.begin(), sr.end());
    map<string, int>mp;
    for(int i = 0;i<n;i++)
    {
        mp[sr[i]] = i;
    }
    string ans = s[0];
    int mini = mp[s[0]];
    for (int i = 1; i < n; i++) {
        string front = s[i] + ans;
        string back  = ans + s[i];
        ans = min(front, back);
    }
    cout<<ans<<endl;

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