#include<bits/stdc++.h>
using namespace std;
#define int long long
int lcm(int a, int b)
{
    return (a*b)/(gcd(a, b));
}
void solve()
{
    int a, b, c, m;
    cin>>a>>b>>c>>m;
    int alice = ((m/a)-(m/(lcm(a, b)))-(m/(lcm(a, c))) + (m/(lcm(c,lcm(a, b)))))*6 + (m/(lcm(c,lcm(a, b))))*2 + ((m/(lcm(a, c))) + (m/(lcm(a, b))) - 2*(m/(lcm(c,lcm(a, b)))))*3;
    int bob = ((m/b)-(m/(lcm(a, b)))-(m/(lcm(b, c))) + (m/(lcm(c,lcm(a, b)))))*6 + (m/(lcm(c,lcm(a, b))))*2 + ((m/(lcm(b, c))) + (m/(lcm(a, b))) - 2*(m/(lcm(c,lcm(a, b)))))*3;
    int carol = ((m/c)-(m/(lcm(c, b)))-(m/(lcm(a, c))) + (m/(lcm(c,lcm(a, b)))))*6 + (m/(lcm(c,lcm(a, b))))*2 + ((m/(lcm(a, c))) + (m/(lcm(c, b))) - 2*(m/(lcm(c,lcm(a, b)))))*3;
    cout<<alice<<" "<<bob<<" "<<carol<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}