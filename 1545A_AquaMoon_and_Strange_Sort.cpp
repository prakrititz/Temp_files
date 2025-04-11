#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> temp(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        temp[i] = a[i];
    }
    map<int, pair<int, int>> mp;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
            mp[temp[i]].first++; // odd
        else
            mp[temp[i]].second++; // even
    }
    for (int i = 0; i < n; i++)
    {
        int cur  = a[i];
        if(i%2)//odd
        {
            if(mp[a[i]].first>0)mp[a[i]].first--;
            else 
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        else{
            if(mp[a[i]].second>0)mp[a[i]].second--;
            else 
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}