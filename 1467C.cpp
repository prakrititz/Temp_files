#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{  
    int n1, n2, n3;
    cin>>n1>>n2>>n3;
    vector<int>a(n1);
    vector<int>b(n2);
    vector<int>c(n3); 
    for(int i = 0;i<n1;i++)cin>>a[i];
    for(int i = 0;i<n2;i++)cin>>b[i];
    for(int i = 0;i<n3;i++)cin>>c[i];
    sort(a.begin(), a.end()), sort(b.begin(), b.end()), sort(c.begin(), c.end());
    int A = accumulate(a.begin(), a.end(), 0LL);
    int B = accumulate(b.begin(), b.end(), 0LL);
    int C = accumulate(c.begin(), c.end(), 0LL);
    vector<int>x = {a[0], b[0], c[0]};
    sort(x.begin(), x.end());
    cout<<max(max(A+B-C, max(C+B-A, A+C-B)), A+B+C-2*(x[0]+x[1]))<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}