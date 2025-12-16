#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&a)
{
    int n = a.size();
    for(int i = 0;i<n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(a[i]>a[j])swap(a[i], a[j]);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n ;i ++)cin>>a[i];
    selectionSort(a);
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