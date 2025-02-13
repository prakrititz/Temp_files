#include <bits/stdc++.h>
using namespace std;

bool isValidDate(const string &date) {
    int dd = stoi(date.substr(0, 2));
    int mm = stoi(date.substr(3, 2));
    int yyyy = stoi(date.substr(6, 4));
    if (yyyy < 2013 || yyyy > 2015) return false;
    if (mm < 1 || mm > 12) return false;
    int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (dd < 1 || dd > days_in_month[mm]) return false;
    return true;
}

int main() {
    string prophecy;
    cin >> prophecy;

    unordered_map<string, int> date_count;
    int n = prophecy.size();

    for (int i = 0; i <= n - 10; i++) {
        string candidate = prophecy.substr(i, 10);

        if (candidate[2] == '-' && candidate[5] == '-' && 
            isdigit(candidate[0]) && isdigit(candidate[1]) && 
            isdigit(candidate[3]) && isdigit(candidate[4]) &&
            isdigit(candidate[6]) && isdigit(candidate[7]) &&
            isdigit(candidate[8]) && isdigit(candidate[9])) {
            
            if (isValidDate(candidate)) {
                date_count[candidate]++;
            }
        }
    }

    pair<string, int> apocalypse_date = {"", 0};
    for (const auto &entry : date_count) {
        if (entry.second > apocalypse_date.second) {
            apocalypse_date = entry;
        }
    }

    cout << apocalypse_date.first << endl;
    return 0;
}
