 #include<bits/stdc++.h>
 using namespace std;
 int main(){
    int tc;
    cin>>tc;
    while(tc--)
    {
        int a, b;
        cin>>a>>b;
        int alternate = min(a, b);
        int remaining = max(a, b) - alternate;
        map<int, int>ways;
        int count = remaining/2;
        ways[count] = 1;
        ways[a+b-count]= 1;
        for(int i = 0; i<alternate; i++)
        {
            count+=2;
            ways[count]++;
            ways[a+b-count]++;
        }
        vector<int>ans;
        for(int i = 0 ;i<=a+b; i++)
        {
            if(ways[i]!=0)ans.push_back(i);
        }
        cout<<ans.size()<<endl;
        for(int i= 0; i< ans.size() ;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
 }