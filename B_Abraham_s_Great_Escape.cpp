#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin>>n>>k;
    if(k == (n*n-1))
    {
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        vector<vector<char>>res(n, vector<char>(n, '0'));
        int i = 0;
        while(i<n)
        {
            int j = 0;
            while(j<n)
            {
                if(k>0){
                    res[i][j] = 'U';
                    k--;
                }    
                else{
                    if(i!=n-1)
                    {
                        res[i][j] = 'D';
                    }
                    else{
                        res[i][j] = 'R';
                    }
                }
                j++;
            }
            i++;
        }
        if(res[n-1][n-1]!='U')res[n-1][n-1] = 'L';
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n; j++)cout<<res[i][j];
            cout<<endl;
        }
}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}