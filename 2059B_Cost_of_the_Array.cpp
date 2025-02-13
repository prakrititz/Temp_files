#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i = 0; i< n ;i++)cin>>a[i];
    if(n==k)
    {
        int count = 1;
        for(int i = 1 ;i<= n ;i+=2)
        {
            if(a[i]!= count)
            {
                cout<<count<<endl;
                return;   
            }
            count++;
        }
        cout<<count<<endl;
    }
    else{
        for(int i = 1;i<= n-k+1;i++)
        {
            if(a[i]!=1)
            {
                cout<<1<<endl;
                return;
            }
        }
        cout<<2<<endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}