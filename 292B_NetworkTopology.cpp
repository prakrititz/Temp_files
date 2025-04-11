#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> gr(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    int deg1  = 0; 
    int deg2 = 0; 
    int degin = 0; 
    bool flag = true;
    for(int i =1 ; i<=n ;i++)
    {
        if(gr[i].size()==1)deg1++;
        if(gr[i].size()==2)deg2++;
        if(gr[i].size()==n-1)degin ++;
    }
    if(deg1 == n-1 && degin == 1)cout<<"star topology"<<endl;
    else if(deg1 ==2 && deg2== n-2)cout<<"bus topology"<<endl;
    else if(deg1==0 && deg2==n)cout<<"ring topology"<<endl;
    else cout<<"unknown topology"<<endl;
    return 0;
}