#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct fenWick{
    int n;
    int k;
    vector<int>arr;
    vector<int>tree;
    fenWick(vector<int>&array)
    {
        build(array);
    }
    void build(vector<int>&array)
    {
        n = array.size();
        arr = array;
        tree.assign(n+1, 0);
        for(int i = 0;i<n;i++)
        {
            int j = i+1;
            while(j<n+1)
            {
                tree[j] += array[i];
                j += (j & (-j));
            }
        }
    }
    void update(int pos, int val)
    {
        int original = arr[pos];
        int diff = val-original;
        arr[pos] = val;
        int j = pos+1;
        while(j<n+1)
        {
            tree[j] += diff;
            j += (j&(-j));
        }
    }
    int sum(int pos)
    {
        int s = 0;
        int j = pos+1;
        while(j>0)
        {
            s += tree[j];
            j -= (j&(-j));
        }
        return s;
    }
    int query(int l, int r)
    {
        return sum(r)-sum(l-1);
    }
};

void solve()
{   
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