#include <bits/stdc++.h>
using namespace std;

int merge(int l, int r, int mid, vector<int>&a, vector<int>&temp)
{
    int count = 0;
    int i1 = l;
    int i2 = mid+1;
    int j = l;
    while(i1<=mid && i2<=r)
    {
        if(a[i1]>a[i2])
        {
            count += mid-i1+1;
            temp[j] = a[i2];
            i2++;
        }
        else{
            temp[j] = a[i1];
            i1++;
        }       
        j++;
    }
    while(i1<=mid)
    {
        temp[j] = a[i1];
        j++;
        i1++;
    }
    while(i2<=r)
    {
        temp[j] = a[i2];
        i2++;
        j++;
    }
    for(int k = l;k<=r;k++)a[k] = temp[k];
    return count;
}
int mergesort(int l, int r, vector<int>&a, vector<int>&temp)
{
    if(l>=r)return 0;
    int mid = (l+r)/2;
    int count = 0;
    count += mergesort(l, mid, a, temp);
    count += mergesort(mid+1, r, a, temp);
    count += merge(l, r, mid, a, temp);
    return count;
}
void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    vector<int>temp(n);
    int inversion = mergesort(0, n-1, a, temp);
    // for(int i =0;i<n ;i++)cout<<a[i]<<" ";
    // cout<<endl;
    cout<<inversion<<endl;
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