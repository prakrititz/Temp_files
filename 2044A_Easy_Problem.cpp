#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        int count = 0;
        map<pair<int, int>, int>mp;
        for(int i = 1; i<=n ;i++)
        {
            for(int j = i; j<=n; j++)
            {
                if((i+j)==n)
                {
                    if(i==j)count++;
                    else count+=2;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}