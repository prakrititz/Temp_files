#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<int ,int>ones;
    vector<vector<int>>edg(n);
    int count = 0;
    int sum = 0;
    int pairs= 0;
    for(int i =0 ;i< 2*n; i++)
    {
        if(s[i]=='(')
        {
            sum+=1;
        }
        else{
            sum-=1;
            count++;
        }
  
    }
    int tcount = 0;
    for(int i = 0;i <s.size()-1; i++)
    {
        if(s[i]==')' && s[i+1]=='(')tcount++;
    }
    cout<<count-tcount<<endl;
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