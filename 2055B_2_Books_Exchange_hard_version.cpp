#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i = 0; i<n ; i++)cin>>a[i];

        map<int, int>mp;
        map<int, int>ans;
        for(int i = 0 ;i <n ; i++)
        {

            if(mp[a[i]]==0)
            {
                vector<int>v;
                int count = 0;
                int curr = a[i]; 
                while(curr!=i+1)
                {
                    v.push_back(curr);
                    mp[curr]++;
                    curr = a[curr-1];
                    count++;
                }
                count++;
                if(v.size()==0)ans[curr]=1;
                else
                {
                for(int i = 0; i< v.size() ;i++)
                {
                    ans[v[i]]= count;
                }
                }
            }
        }
        for(int i = 0; i<n ;i++)cout<<ans[i+1]<<" ";
        cout<<endl;
    }
    return 0;

}