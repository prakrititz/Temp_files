#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solve()
{ 
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = a[n-1];
    int dp = 0; 
    int max_term = sum + dp; 

    for(int i = n - 2; i >= 0; i--) {
        int nottake = -sum;
        int take = a[i] - sum + max_term;

        dp = max(take, nottake);
        sum += a[i]; 
        max_term = max(max_term, sum + dp);
    }

    cout << dp << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}