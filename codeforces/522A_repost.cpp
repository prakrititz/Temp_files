#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    map<string, int> chain_length;
    chain_length["polycarp"] = 1;

    for (int i = 0; i < n; ++i) {
        string name1, reposted, name2;
        cin >> name1 >> reposted >> name2;
        transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
        transform(name2.begin(), name2.end(), name2.begin(), ::tolower);
        chain_length[name1] = chain_length[name2] + 1;
    }
    int max_chain = 0;
    for (const auto& entry : chain_length) {
        max_chain = max(max_chain, entry.second);
    }

    cout << max_chain << endl;

    return 0;
}
