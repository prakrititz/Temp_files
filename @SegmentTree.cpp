#include<bits/stdc++.h>
using namespace std;
struct SegmentTree
{
    int n;
    int k;
    int size;  
    vector<int>Tree;
    SegmentTree(vector<int>&array)
    {
        BuildSt(array);
    }
    void BuildSt(vector<int>&a)
    {
        n = a.size();
        k = 1;
        while(k<n){
            k <<=1;
        }
        size = 2*k-1;
        Tree.assign(size, 0);
        for(int i = 0;i<n;i++)
        {
            Tree[i+k-1] = a[i];
        }
        for(int j = k-2;j>=0;j--)
        {
            Tree[j] = Tree[2*j+1]+Tree[2*j+2];
        }
    }
    void update(int pos , int val)
    {
        int ind = k-1+pos;
        Tree[ind] = val;
        int j  = (ind-1)/2;
        while(j>=0)
        {
            Tree[j] = Tree[2*j+1]+Tree[2*j+2];
            if(j==0)break;
            j = (j-1)/2;
        }
    }
    int queryUtil(int ss, int se, int l, int r, int cur)
    {
        if(r<ss || se<l)return 0;
        if(l<=ss && r>=se)return Tree[cur];
        int m1 = 0, m2 = 0;
        int mid = (ss+se)/2;
        if(2*cur+1<size)m1 = queryUtil(ss, mid, l, r, 2*cur+1);
        if(2*cur+2<size)m2 = queryUtil(mid+1, se, l, r, 2*cur+2);
        return m1+m2;
    }
    int query(int l, int r)
    {
        return queryUtil(0, k-1,l, r, 0);
    }
};
