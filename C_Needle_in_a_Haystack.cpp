#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solve()
{ 
    string s;
    cin >> s;
    string t;
    cin >> t;
    multiset<int> ms1, ms2;
    for(char c : t) ms1.insert(c - 'a');
    for(char c : s) ms2.insert(c - 'a');
    for(char c : s)
    {
        auto it = ms1.find(c - 'a');
        if(it == ms1.end()){
            cout << "Impossible"<<endl;
            return;
        }
        ms1.erase(it);
    }
    vector<int> a;
    for(int x : ms1) a.push_back(x);

    string ans = "";
    int i = 0;
    for(char c : s)
    {
        int cur = c - 'a';

        while(i < a.size() && a[i] < cur)
        {
            ans.push_back(char('a' + a[i]));
            i++;
        }

        ans.push_back(c);
    }
    while(i < a.size())
    {
        ans.push_back(char('a' + a[i]));
        i++;
    }
    cout << ans << endl;
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
