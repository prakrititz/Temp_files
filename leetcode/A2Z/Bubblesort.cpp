#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>&a)
{
    int n = a.size();
    for(int i = n-1;i>0;i--)
    {
        for(int j = 0;j<i;j++)
        {
            if(a[j]<a[j+1])swap(a[j], a[j+1]);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n ;i ++)cin>>a[i];
    bubble_sort(a);
    for(int i = 0;i<n ;i++)cout<<a[i]<<" ";
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