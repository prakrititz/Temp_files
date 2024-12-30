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
        x--;y--;
        vector<int>a(n);
        for(int i = 0;i< n ;i++)a[(x+i)%n] = i%2;
        if(n%2!=0|| (x-y)%2==0){
            a[x] = 2;
        }
        for(int i = 0;i <n; i++)cout<<a[i]<<" ";
        cout<<endl;

    }
    return 0;
}