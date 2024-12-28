#include<bits/stdc++.h>
long long fact(long long n)
{
    if(n==0 || n==1)return 1;
    else{
        return n*fact(n-1);
    }
}

using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n, d;
        cin>>n>>d;
        vector<int>ans;
        ans.push_back(1);
        if(d%5==0)
        {
            ans.push_back(5);
        }
        if(d%3==0 || (n>=3))
        {
            ans.push_back(3);
        }
        if(d%9==0 || (n>=6) || (n>=3 && d%3==0))
        {
            ans.push_back(9);
        }
        if(d%7==0 || n>=7 || fact(n)%6==0)
        {
            ans.push_back(7);
        }
        sort(ans.begin(), ans.end());
        for(int i = 0 ;i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }   

    return 0;
}