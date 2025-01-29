#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[a[i]]++;
    }
    if(n==1)
    {
        cout<<1<<endl;
        return ;
    }
    int count = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
        if(s[a[i]]>=2)
        {
            count++;s[a[i]] = -1;
        }
        else if(s[a[i]]==1)  b++;  
    }
    cout <<count + (b+1)/2<< endl;
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