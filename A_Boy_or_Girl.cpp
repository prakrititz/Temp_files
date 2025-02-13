#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;
    map<char, int>mp;
    int n= s.size(); int count = 0;
    for(int i = 0;i<n ;i++)
    {
        if(mp[s[i]]==0)
        {
            count++;
            mp[s[i]]++;
        }
    }
    if(count%2==0)
    {
        cout<<"CHAT WITH HER!"<<endl;
    }
    else{
        cout<<"IGNORE HIM!"<<endl;
    }

    return 0;
}