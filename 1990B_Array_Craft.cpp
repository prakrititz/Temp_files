#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n, x, y;
        cin>>n>>x>>y;
        x--; y--;
        if(x==y)
        {
            vector<int>ans(n);
            ans[x] = 1;
            for(int i = 0; i<n ; i++)
            {
                if(i!=x)ans[i]=-1;
            }
            for(int i = 0; i<n ;i++)cout<<ans[i]<<" ";
            cout<<endl;
        }
        else{
            vector<int>ans(n);
            for(int i = y; i<=x; i++)ans[i] = 1;
            int back = -1;
            for(int i = y-1; i>=0; i--)
            {
                ans[i] = back;
                back*=-1;
            }
            int front = -1;
            for(int i = x+1; i< n; i++){
                ans[i] = front;
                front*=-1;
            }
            for(int i = 0; i< n;i ++)cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}