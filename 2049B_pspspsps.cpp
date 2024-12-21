// 
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
        string s;
        cin>>s;
        int pCount = 0;
        int sCount = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='p')
            {
                pCount++;
            }
            else if(s[i]=='p')
            {
                sCount++;
            }
        }
        int first_p= -1;
        for(int i = 0; i< n ;i++)
        {
            if(s[i]=='p')
            {
                first_p=i;
                break;
            }
        }
        bool pBeforeS = false;
        if(first_p!=-1)
        {
            int last_p = -1;
            for(int i = first_p; i< n; i++)
            {
                if(s[i]=='s')
                {
                    pBeforeS = true;
                    break;
                }
            }
        }
        if(pBeforeS)
        {
            cout<<"NO"<<endl;
        }
        else{
            if(pCount==0 || sCount==0)
            {
                cout<<"YES"<<endl;
            }
            else if(pCount == 1 && s[n-1]=='p')
            {
                cout<<"YES"<<endl;
            }
            else if(sCount == 1 && s[0]=='s')
            {
                cout<<"YES"<<endl;
            }
            else 
            {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}