#include<bits/stdc++.h>
using namespace std;
#define int long long 
int stb(string s)
{
    int ans = 0;
    int n = s.size();
    int k = 1;
    for(int i = n-1;i>=0;i--)
    {
        if(s[i]=='1')ans+=k;
        k*=2;
    }
    return ans;
}

void solve()
{   
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        a[i] = stb(s);
    }
    sort(a.begin(), a.end());
    int l = 0, r = (1LL<<m) - 1;
    int half = ((1LL<<m) - n - 1) / 2;
    int ans = -1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        int cnt = mid+1 - (int)(upper_bound(a.begin(), a.end(), mid) - a.begin());
        if(cnt > half)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }   
    string s= "";
    while(m--)
    {
        if(ans%2)s+="1";
        else s+="0";
        ans/=2;
    }
    reverse(s.begin(), s.end());
    cout<<s<<endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
