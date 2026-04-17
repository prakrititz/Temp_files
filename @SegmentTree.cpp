#include<bits/stdc++.h>
using namespace std;
#define int long long
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
    int quer_func(int ss, int se, int l, int r, int cur)
    {
        if(r<ss || se<l)return 0;
        if(l<=ss && r>=se)return Tree[cur];
        int m1 = 0, m2 = 0;
        int mid = (ss+se)/2;
        if(2*cur+1<size)m1 = quer_func(ss, mid, l, r, 2*cur+1);
        if(2*cur+2<size)m2 = quer_func(mid+1, se, l, r, 2*cur+2);
        return m1+m2;
    }
    int query(int l, int r)
    {
        return quer_func(0, k-1,l, r, 0);
    }
};


struct SegmentTree_lazy{
    int n;
    int k;
    int size;
    vector<int>t;
    vector<int>lazy;
    void update(int pos, int val){
        int current_val = query(pos, pos);
        update_range(pos, pos, val-current_val);
    }
    void push(int ss, int se, int curr)
    {
        if(lazy[curr]!=0)
        {
            t[curr] += (se-ss+1)*lazy[curr];
            if(ss!=se)
            {
                lazy[2*curr+1] += lazy[curr];
                lazy[2*curr+2] += lazy[curr];
            }
            lazy[curr] = 0;
        }
    }
    void update_range(int l, int r, int val)
    {
        return update_range_func(l, r, 0, k-1, 0, val);
    }
    void update_range_func(int l, int r, int ss, int se, int curr, int val)
    {
        push(ss, se, curr);
        if(r<ss || l>se)return;
        if(l<=ss && se<=r)
        {
            lazy[curr]+=val;
            push(ss, se, curr);
            return;
        }
        int mid = (ss+se)/2;
        update_range_func(l, r, ss, mid, 2*curr+1, val);
        update_range_func(l, r, mid+1,  se, 2*curr+2, val);
        t[curr] = t[2*curr+1] + t[2*curr+2];
        return;
    }
    int query(int l, int r)
    {
        return query_func(l ,r, 0, k-1, 0);
    }
    int query_func(int l, int r, int ss, int se, int curr)
    {
        push(ss, se, curr);
        if(r<ss || l>se)return 0;
        if(l<=ss && se<=r)
        {
            return t[curr];
        }
        int mid = (ss+se)/2;
        return query_func(l,r, ss, mid, 2*curr+1) + query_func(l, r, mid+1, se, 2*curr+2);
    }
    void build(vector<int>&array)
    {
        n = array.size();
        k = 1;
        while(k<n)k*=2;
        size = 2*k-1;
        t.assign(size, 0);
        lazy.assign(size,0);
        for(int i = 0;i<n;i++)
        {
            t[k-1+i] = array[i];
        }
        for(int i = k-2;i>=0;i--)
        {
            t[i] = t[2*i+1]+t[2*i+2];
        }
    }
    SegmentTree_lazy(vector<int>&arr)
    {
        build(arr);
    }
};



struct SegmentTree_lazy_set_add{
    int n;
    int k;
    int size;
    vector<int>t;
    vector<int>lazy_add;
    vector<int>lazy_set;
    void update(int pos, int val){ // point update
        int current_val = query(pos, pos);
        update_range_add(pos, pos, val-current_val);
    }
    void push(int ss, int se, int curr, bool flag)
    {
        if(flag == 1)// its a set update;
        {   
            t[curr] = (se-ss+1)*lazy_set[curr];
            if(ss!=se){
                lazy_set[2*curr+1] = lazy_set[curr];
                lazy_set[2*curr+2] = lazy_set[curr];
                lazy_add[2*curr+1] = 0;
                lazy_add[2*curr+2] = 0;
            }
            lazy_set[curr] = 0;
        }
        else{ // its a add update;
            // lazy_set[curr] should have been += val
            t[curr] += (se-ss+1)*lazy_add[curr];
            if(ss!=se)
            {
                if(lazy_set[2*curr+1]) lazy_set[2*curr+1] += lazy_add[curr];
                else lazy_add[2*curr+1] += lazy_add[curr];
                
                if(lazy_set[2*curr+2]) lazy_set[2*curr+2] += lazy_add[curr];
                else lazy_add[2*curr+2] += lazy_add[curr];
            }
            lazy_add[curr] = 0; 
        }
    }

    void update_range_set(int l, int r, int val)
    {
        return update_range_set_func(l, r, 0, k-1, 0, val);
    }
    void update_range_set_func(int l, int r, int ss, int se, int curr, int val)
    {
        if(lazy_set[curr] && !lazy_add[curr]) push(ss, se, curr, 1);
        else if(lazy_add[curr] && !lazy_set[curr]) push(ss, se,curr, 0);
        
        if(r<ss || l>se)return;
        if(l<=ss && se<=r)
        {
            lazy_set[curr]=val;
            push(ss, se, curr, 1);
            return;
        }
        int mid = (ss+se)/2;
        update_range_set_func(l, r, ss, mid, 2*curr+1, val);
        update_range_set_func(l, r, mid+1,  se, 2*curr+2, val);
        t[curr] = t[2*curr+1] + t[2*curr+2];
        return;
    }

    void update_range_add(int l, int r, int val)
    {
        return update_range_add_func(l, r, 0, k-1, 0, val);
    }
    void update_range_add_func(int l, int r, int ss, int se, int curr, int val)
    {
        if(lazy_set[curr] && !lazy_add[curr]) push(ss, se, curr, 1);
        else if(lazy_add[curr] && !lazy_set[curr]) push(ss, se,curr, 0);
        
        if(r<ss || l>se)return;
        if(l<=ss && se<=r)
        {
            lazy_add[curr]+=val;
            push(ss, se, curr, 0);
            return;
        }
        int mid = (ss+se)/2;
        update_range_add_func(l, r, ss, mid, 2*curr+1, val);
        update_range_add_func(l, r, mid+1,  se, 2*curr+2, val);
        t[curr] = t[2*curr+1] + t[2*curr+2];
        return;
    }
    int query(int l, int r)
    {
        return query_func(l ,r, 0, k-1, 0);
    }
    int query_func(int l, int r, int ss, int se, int curr)
    {
        if(lazy_set[curr] && !lazy_add[curr]) push(ss, se, curr, 1);
        else if(lazy_add[curr] && !lazy_set[curr]) push(ss, se,curr, 0);

        if(curr>=size) return 0;
        if(r<ss || l>se)return 0;
        if(l<=ss && se<=r)
        {
            return t[curr];
        }
        int mid = (ss+se)/2;
        return query_func(l,r, ss, mid, 2*curr+1) + query_func(l, r, mid+1, se, 2*curr+2);
    }
    void build(vector<int>&array)
    {
        n = array.size();
        k = 1;
        while(k<n)k*=2;
        size = 2*k-1;
        t.assign(size, 0);
        lazy_add.assign(size,0);
        lazy_set.assign(size, 0);
        for(int i = 0;i<n;i++)
        {
            t[k-1+i] = array[i];
        }
        for(int i = k-2;i>=0;i--)
        {
            t[i] = t[2*i+1]+t[2*i+2];
        }
    }
    void print_tree()
    {
        for(auto it: t)cout<<it<<" ";
        cout<<endl;
    }
    SegmentTree_lazy_set_add(vector<int>&arr){
        build(arr);
    }
};

void solve()
{
    int n, q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i = 0;i<n ;i++)cin>>a[i];
    SegmentTree_lazy_set_add st(a);
    while(q--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int a, b, val;
            cin>>a>>b>>val;
            a--, b--;
            st.update_range_add(a, b, val);
        }
        else if(x==2)
        {
            int a, b, val;
            cin>>a>>b>>val;
            a--, b--;
            st.update_range_set(a, b, val);
        }
        else{
            int a, b;
            cin>>a>>b;
            a--, b--;
            // st.print_tree();
            cout<<st.query(a, b)<<endl;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}