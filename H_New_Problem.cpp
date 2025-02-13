#include <bits/stdc++.h>
using namespace std;

void insertSubstrings(const string &s, unordered_set<string> &substrings) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
        string sub = "";
        for (int j = i; j < len; j++) {
            sub += s[j];
            substrings.insert(sub);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    unordered_set<string> substrings;
    for (int i = 0; i < n; i++) {
        string title;
        cin >> title;
        insertSubstrings(title, substrings);
    }
    queue<string> q;

    for (char c = 'a'; c <= 'z'; c++) {
        string s(1, c);
        q.push(s);
    }
    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (substrings.find(current) == substrings.end()) {
            cout << current << endl;
            return 0;
        }

        if (current.length() < 3) { 
            for (char c = 'a'; c <= 'z'; c++) {
                q.push(current + c);
            }
        }
    }

    return 0;
}
