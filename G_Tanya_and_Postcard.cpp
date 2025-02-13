#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    unordered_map<char, int> s_freq, t_freq;
    int yay = 0, whoops = 0;
    for (char c : s) s_freq[c]++;
    for (char c : t) t_freq[c]++;
    for (char c = 'A'; c <= 'Z'; c++) {
        int match = min(s_freq[c], t_freq[c]);
        yay += match;
        s_freq[c] -= match;
        t_freq[c] -= match;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        int match = min(s_freq[c], t_freq[c]);
        yay += match;
        s_freq[c] -= match;
        t_freq[c] -= match;
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        int match = min(s_freq[c], t_freq[c + 32]);
        whoops += match;
        s_freq[c] -= match;
        t_freq[c + 32] -= match;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        int match = min(s_freq[c], t_freq[c - 32]);
        whoops += match;
        s_freq[c] -= match;
        t_freq[c - 32] -= match;
    }
    cout << yay << " " << whoops << endl;
    return 0;
}
