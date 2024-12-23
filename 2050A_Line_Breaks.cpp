#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        int k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i = 0; i<n; i++)
        {
            string s; 
            cin>>s;
            a[i] = s.size();
        }
        int i = 0;
        while(i<n && k-a[i]>=0)
        {
            k-=a[i];
            i++;
        }
        cout<<i<<endl;
    }
    return 0;
}