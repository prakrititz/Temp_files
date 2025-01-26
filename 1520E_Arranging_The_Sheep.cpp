#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin>>n;
    string s;
    long long first = -1; 
    long long last = -1;
    cin>>s;long long count = 0;
    for(long long i =0;i<n; i++)
    {
        if(s[i]=='*')
        {   last = i;
            count++;
            if(first==-1)first = i;
        }
    }
    if(count<=1)
    {
        cout<<0<<endl;
        return ;
    }
    long long count2 =0;long long ind;
    for (long long i = 0; i < n; i++){  if(s[i]=='*')count2++;
        if(count2==(count+1)/2)
        {
            ind = i;
            break;
        }
    }
    long long added = 0;long long ans = 0;
    for(long long i = ind-1; i>=first;i--)
    {   
        if(s[i]=='*')
        {
            ans += ind-i-1-added;
            added++;
        }
    }
    // cout<<added;
    added = 0;
    for(long long i = ind+1; i<=last; i++)
    {
        if(s[i]=='*')
        {
            ans += i-ind-1-added;
            added++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}