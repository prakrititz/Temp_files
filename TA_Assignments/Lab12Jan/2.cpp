







#include<bits/stdc++.h>
using namespace std;
#define int long long  // This will rename all int to long long if this line is not used all int must be replaced with long long or long long int
// Background we will use codes/ideas from previous question here/


//Question
// Given A, n, m, 2 ≤m ≤10e6, A is a k∗k, 0 < k < 100 matrix, find
// A^n(mod m).
//simple matrix_mult
vector<vector<int>>mat_mult(vector<vector<int>>&a, vector<vector<int>>&b, int m)
{
    int n = a.size();
    vector<vector<int>>res(n, vector<int>(n));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            for(int k =0;k<n;k++)
            {
                res[i][j] = (res[i][j] + (a[i][k]*b[k][j])%m)%m;
            }
        }
    }
    return res;
}

// now to take power;
vector<vector<int>>mat_pow_a(vector<vector<int>>&a, int n, int m)
{
    //simple method;
    vector<vector<int>>res(n, vector<int>(n, 0));
    for(int i = 0;i<a.size();i++)a[i][i]=1;
    while(n--)res = mat_mult(res, a, m);
    return res;
}
vector<vector<int>>mat_pow_a_binExp(vector<vector<int>>&a, int n, int m)
{
    //simple method;
    int k = a.size();
    vector<vector<int>>res(k, vector<int>(k, 0));
    for(int i = 0;i<k;i++)res[i][i]=1;
    while(n>0)
    {
        if(n%2)res = mat_mult(res, a, m);
        n/=2;
        a = mat_mult(a, a, m);
    }
    return res;
}
vector<vector<int>>mat_pow_b(vector<vector<int>>&a, string n, int m)
{
    int k = a.size();
    vector<vector<int>>res(k, vector<int>(k, 0));
    for(int i = 0;i<k;i++)res[i][i]=1;
    for(int i = n.size()-1;i>=0;i--)
    {
        if(n[i]=='1')res = mat_mult(res, a, m);
        a = mat_mult(a, a, m);
    }
    return res;
}

vector<vector<int>>mat_pow_b(vector<vector<int>>&a, string n, int m)
{
    int k = a.size();
    vector<vector<int>>res(k, vector<int>(k, 0));
    for(int i = 0;i<k;i++)res[i][i]=1;
    for(int i = n.size()-1;i>=0;i--)
    {
        if(n[i]=='1')res = mat_mult(res, a, m);
        a = mat_mult(a, a, m);
    }
    return res;
}

vector<vector<int>>mat_pow_c(vector<vector<int>>&a, string n, int m)
{
    int k = a.size();
    vector<vector<int>>res(k, vector<int>(k, 0));
    for(int i = 0;i<k;i++)res[i][i]=1;
    vector<vector<int>>base = a;
    vector<vector<int>>temp;
    vector<vector<int>>temp2;
    for(int i = n.size()-1;i>=0;i--)
    {
        for(int j = 0;j<n[i]-'0';j++)
        {   
            res = mat_mult(res, base,m);
        }
        temp = mat_mult(base, base, m);
        temp2 = mat_mult(temp, temp, m);
        temp2 = mat_mult(temp2, temp2, m);
        base = mat_mult(temp2, temp,m);        
    }
    return res;
}
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