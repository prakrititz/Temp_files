#include <bits/stdc++.h>
using namespace std;
long long mod = 676767677;
int check (vector<pair<int, int>>&a, vector<int>b)
{
    int x = 1;
    for(int i = 0;i<a.size();i++)
    {
        if(a[i].first==0  && a[i].second==0){
            x  = 0;
            return x;
        }
    }
    int sum = 1;
    for(int i = 1;i<a.size(); i++)
    {
        sum += a[i].second;
    }
    if(sum!=b[0])x = 0;
    return x;
}

void solve() {
    int n;
    cin>>n;vector<int>a(n);
    
    for(int i = 0;i<n ;i++)cin>>a[i];
    if(n==1 || a[0]>n)
    {
        cout<<2<<endl;
        return;   
    }
    vector<pair<int, int>>b1(n), b2(n);
    b1[0] = {1, 0};
    b2[0] = {0, 1};
    bool t1 = 1;
    bool t2 = 1;
    for(int i = 1;i<n;i++)
    {
        if((a[i]-a[i-1])==1)
        {
            if(b1[i-1].first ==0)
            {
                t1 = false;
            }
            else{
                b1[i].first = 1;
            }   
            if(b2[i-1].first==0)
            {
                t2 = false;
            }
            else{
                b2[i].first = 1;
            }
        }
        else if((a[i]-a[i-1])== -1)
        {
            if(b1[i-1].first ==1)
            {
                t1 = false;
            }
            else{
                b1[i].second = 1;
            }   
            if(b2[i-1].first==1)
            {
                t2 = false;
            }
            else{
                b2[i].second = 1;
            }
        }
        else if((a[i]-a[i-1])==0)
        {
            if(b1[i-1].first ==0)
            {
                b1[i].first = 1;
            }
            else{
                b1[i].second = 1;
            }
            if(b2[i-1].first==0)
            {
                b2[i].first = 1;
            }
            else{
                b2[i].second = 1;
            }
        }
        else{
            cout<<0<<endl;
            return;
        }
        if(t1==false && t2 == false)
        {
            cout<<0<<endl;
            return;
        }
    }
    cout<<check(b1, a)+ check(b2, a)<<endl;

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