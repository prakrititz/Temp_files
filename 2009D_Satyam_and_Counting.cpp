#include<bits/stdc++.h>
using namespace std;
int binSearch(vector<pair<int, int>>&a, int target)
{
    int l = 0; int r = a.size()-1;
    while(l<=r)
    {
        int mid = l + (r - l) / 2;
        if(a[mid].first==target)return mid;
        if(a[mid].first>target)r = mid-1;
        else l = mid+1; 
    }
    return -1;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>>y_0;
        vector<pair<int,int>>y_1;
        map<int, int>X;
        for(int i =0 ;i< n ; i++)
        {
            int x, y;
            cin>>x>>y;
            if(y==0)
            {
                X[x]++;
                y_0.push_back({x, y});
            }
            else{
                X[x]++;
                y_1.push_back({x, y});
            }
        }
        sort(y_1.begin(), y_1.end());
        sort(y_0.begin(), y_0.end());
        int i = 0, j = 0; 
        long long count = 0; 
        for(int i = 0 ;i< y_1.size(); i++)
        {
            if(X[y_1[i].first]==2){
                int ind = binSearch(y_0, y_1[i].first);
                count += (y_0.size()-ind-1);      //base_bottom_right
                count += ind;        //base_bottom_left
            }
            if(binSearch(y_0,y_1[i].first-1)!=-1 && binSearch(y_0,y_1[i].first+1)!=-1)
            {
                count++;      //base_between_bottom
            }
        }
        for(int i = 0 ;i< y_0.size(); i++)
        {
            if(X[y_0[i].first]==2){
                int ind = binSearch(y_1, y_0[i].first);
                count += (y_1.size()-ind-1);        //base_top_right
                count += ind;            //base_top_left
            }
            if(binSearch(y_1,y_0[i].first-1)!=-1 && binSearch(y_1,y_0[i].first+1)!=-1)
            {
                count++;      //base_between_top  
            }
        }
        cout<<count<<endl;
    }
    return 0;
}