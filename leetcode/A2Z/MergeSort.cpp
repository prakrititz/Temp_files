#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&a, vector<int>&temp, int l, int r)
{
    if(l>=r)return;
    int mid = (l+r)/2;
    int i1 = l;
    int i2 = mid+1;
    int j = l;
    while(i1<=mid && i2<=r)
    {
        if(a[i1]>a[i2])
        {
            temp[j]=(a[i2]);
            i2++;
        }
        else{
            temp[j]=(a[i1]);
            i1++;
        }
        j++;
    }
    while(i1<=mid)
    {
        temp[j]=(a[i1]);
        i1++;
        j++;
    }
    while(i2<=r)
    {
        temp[j]=(a[i2]);
        i2++;
        j++;
    }
}

void mergesort(vector<int>&a, int l , int r, vector<int>&temp)
{
    if(l>=r)return;
    int mid = (l+r)/2;
    mergesort(a, l, mid, temp);
    mergesort(a, mid+1, r, temp);
    merge(a,temp, l, r);
    for (int i = l; i <= r; ++i) a[i] = temp[i];
}

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>temp(n);
    for(int i = 0;i<n ;i ++)cin>>a[i];
    mergesort(a, 0, n-1, temp);
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