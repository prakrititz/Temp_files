#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mini = min(mini, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        a[i] -= mini;
    }
    sort(a.begin(), a.end());
    if(a[0]!=a[1])
    {
        cout<<"No"<<endl;
        return;
    }   
    // for (int i = 0; i < n; i++) {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    int curr = 0;
    for (int i = 2; i < n; i+=2)
    {
        if(a[i]==a[i+1] && a[i]>curr){
            curr = a[i];
        }
        else if(a[i]<=curr && a[i+1]<=curr+1){
            curr++;
        }
        else{
            cout<<"No"<<endl;
            return;
        }

    }
    cout <<"Yes"<<endl;
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