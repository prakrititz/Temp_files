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
        map<char, int>mp;
        for(int i =0 ;i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        int mini = INT_MAX;
        char mi, ma;
        int maxi = INT_MIN;
        for(int i = 0; i< s.size(); i++)
        {
            if(mp[s[i]]<mini)
            {
                mini = mp[s[i]];
                mi = s[i];
            }
            if(mp[s[i]]>maxi)
            {
                maxi = mp[s[i]];
                ma = s[i];
            }
        }
        if(mini!=maxi)
        {
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i]==mi)
            {
                s[i] = ma;
                break;
            }
        }
        }
        
        else{
            for(int i = 0;i<s.size();i++)
            {
                if(s[i]!=mi)
                {
                    s[i]=mi;
                    break;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;

}