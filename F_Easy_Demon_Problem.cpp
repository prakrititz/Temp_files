#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solve()
{   
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    int A = 0, B = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        A += a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        B += b[i];
    }
    unordered_set<int> S1, S2;
    S1.reserve(n * 2);
    S2.reserve(m * 2);

    for(int i = 0; i < n; i++)
        S1.insert(A - a[i]);
    for(int j = 0; j < m; j++)
        S2.insert(B - b[j]);
    int AB = A * B;
    while(q--)
    {
        int x;
        cin >> x;
        int need = x;
        bool ok = false;
        for(int d = 1; d * d <= llabs(need); d++)
        {
            if(need % d != 0) continue;
            int p1 = d;
            int q1 = need / d;
            int p2 = -d;
            int q2 = -q1;
            if( (S1.count(p1) && S2.count(q1)) ||
                (S1.count(q1) && S2.count(p1)) ||
                (S1.count(p2) && S2.count(q2)) ||
                (S1.count(q2) && S2.count(p2)) )
            {
                ok = true;
                break;
            }
        }
        if(ok)
        {            
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
