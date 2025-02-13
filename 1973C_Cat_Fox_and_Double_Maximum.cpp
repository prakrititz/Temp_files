#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int>p(n);
    for(int i = 0; i< n; i++)cin>>p[i];
    vector<int>q1(n);
    vector<int>q2(n);
    vector<pair<int, int>>pr;vector<pair<int, int>>pr2;
    vector<pair<int, int>>pp;vector<pair<int, int>>pp2;
    for(int i = 1;i < n-1;i+=2)
    {
        pr.push_back({p[i], i});
    }
    for(int i = 0; i<n ; i+=2)
    {

        pr2.push_back({p[i], i});
    }
    pr2.push_back({p[n-1], n-1});
    sort(pr.begin(), pr.end());
    sort(pr2.begin(), pr2.end());
    int curr = n;
    for(int i = 0; i<pr.size(); i++)
    {
        q1[pr[i].second]= curr;
        curr--;
    }
    for(int i = 0; i<pr2.size(); i++)
    {
        q1[pr2[i].second] = curr;
        curr--;
    }
    for(int i = 2;i < n;i+=2)
    {
        pp.push_back({p[i], i});
    }
    for(int i = 1; i<n ; i+=2)
    {

        pp2.push_back({p[i], i});
    }
    pp2.push_back({p[0], 0});
    sort(pp.begin(), pp.end());
    sort(pp2.begin(), pp2.end());
    curr = n;
    for(int i = 0; i<pp.size(); i++)
    {
        q2[pp[i].second]= curr;
        curr--;
    }
    for(int i = 0; i<pp2.size(); i++)
    {
        q2[pp2[i].second] = curr;
        curr--;
    }
    int qq1 = 0; int qq2 = 0;
    for(int i = 1;i< n-1; i++)
    {
        if((q1[i]+p[i])>(q1[i-1]+p[i-1]) && (q1[i]+p[i])>(q1[i+1]+p[i+1]))
        {
            qq1++;
        }
        if((q2[i]+p[i])>(q2[i-1]+p[i-1]) && (q2[i]+p[i])>(q2[i+1]+p[i+1]))
        {
            qq2++;
        }
    }
    if(qq1>=qq2)
    {
        for(int i= 0; i<n ;i++)cout<<q1[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i = 0;i<n;i++)cout<<q2[i]<<" ";
    cout<<endl;
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