#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&a)
{
    int n = a.size();
    for(int i = n-1;i>=0;i--)
    {
        int j = i;
        while(j+1<n && a[j]>a[j+1])
        {
            swap(a[j], a[j+1]);
            j++;
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n ;i ++)cin>>a[i];
    insertionSort(a);
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