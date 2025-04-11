#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> p;
    while (n--) {
        string c;
        cin >> c;
        if (c == "pwd") {
            cout << "/";
            for (string &d : p) cout << d << "/";
            cout << "\n";
        } else {
            string s;
            cin >> s;
            if (s[0] == '/') p.clear();
            stringstream ss(s);
            while (getline(ss, s, '/')) {
                if (s == "..") p.pop_back();
                else if (!s.empty()) p.push_back(s);
            }
        }
    }
}
