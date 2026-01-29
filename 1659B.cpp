#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    int n, k;
    cin >> n >> k;
    int f = k;
    string s;
    cin >> s;
    vector<int> a(n, 0);
    string s2 = s;
    for(int i = 0; i < n - 1; i++)
    {
        if(f % 2 == 1)
        {
            if(s[i] == '1') {
                if(k > 0) {
                    a[i] = 1;
                    k--;
                    s2[i] = '1';
                } else {
                    s2[i] = '0';
                }
            }
            else { 
                s2[i] = '1';
            }
        }
        else
        {
            if(s[i] == '0') {
                if(k > 0) {
                    a[i] = 1;
                    k--;
                    s2[i] = '1';
                } else {
                    s2[i] = '0';
                }
            }
            else {
                s2[i] = '1';
            }
        }
    }
    a[n-1] = k;
    int flips_on_last = f - k;
    if(flips_on_last % 2 == 1) {
        if(s[n-1] == '1') s2[n-1] = '0';
        else s2[n-1] = '1';
    } else {
        s2[n-1] = s[n-1];
    }

    cout << s2 << endl;
    for(auto it: a) cout << it << " ";
    cout << endl;
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