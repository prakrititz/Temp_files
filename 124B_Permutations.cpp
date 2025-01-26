#include <bits/stdc++.h>
using namespace std;
void generatePermutations(vector<int>& perm, int l, int r, vector<vector<int>>& allPermutations) {
    if (l == r) {
        allPermutations.push_back(perm);
        return;
    }
    for (int i = l; i <= r; ++i) {
        swap(perm[l], perm[i]);  
        generatePermutations(perm, l + 1, r, allPermutations);
        swap(perm[l], perm[i]);        
    }
}
int rearrangeNumber(const string& num, const vector<int>& perm) {
    string rearranged = num;                  
    for (int i = 0; i < perm.size(); ++i) {
        rearranged[i] = num[perm[i]];
    }
    return stoi(rearranged); 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<string> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<int> perm(k);
    for (int i = 0; i < k; ++i) {
        perm[i] = i;
    }
    vector<vector<int>> allPermutations;
    generatePermutations(perm, 0, k - 1, allPermutations);
    int minDifference = INT_MAX;
    for (const vector<int>& currentPerm : allPermutations) {
        vector<int> rearrangedNumbers;

        for (const string& number : numbers) {
            int rearranged = rearrangeNumber(number, currentPerm);
            rearrangedNumbers.push_back(rearranged);
        }

        int maxVal = INT_MIN, minVal = INT_MAX;
        for (int num : rearrangedNumbers) {
            maxVal = max(maxVal, num);
            minVal = min(minVal, num);
        }

        minDifference = min(minDifference, maxVal - minVal);
    }
    cout << minDifference << endl;
    return 0;
}

