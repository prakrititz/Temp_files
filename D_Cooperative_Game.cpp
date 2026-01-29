#include<bits/stdc++.h>
using namespace std;
#define int long long 

vector<string> ask(const vector<int>& ids) {
    cout << "next";
    for (int id : ids) {
        cout << " " << id;
    }
    cout << endl;
    int k;
    cin >> k;
    vector<string> groups(k);
    for(int i = 0; i < k; ++i) {
        cin >> groups[i];
    }
    return groups;
}

bool are_together(const vector<string>& groups, char id1, char id2) {
    for(const string& g : groups) {
        bool has1 = false, has2 = false;
        for(char c : g) {
            if(c == id1) has1 = true;
            if(c == id2) has2 = true;
        }
        if(has1 && has2) return true;
    }
    return false;
}

void solve()
{   
    while(true) {
        ask({0, 1});
        vector<string> groups = ask({0});
        if(are_together(groups, '0', '1')) {
            break;
        }
    }
    vector<int> all_friends = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while(true) {
        vector<string> groups = ask(all_friends);
        if(groups.size() == 1) {
            cout << "done" << endl;
            return;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--)
    {
        solve();
    }
    return 0;
}