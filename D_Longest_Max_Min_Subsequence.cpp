#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 400000;


int main() {
    int testCases;
    cin >> testCases;
    int arr[MAX_SIZE], countArr[MAX_SIZE], posArr[MAX_SIZE];
    bool visited[MAX_SIZE];
    vector<int> indices[MAX_SIZE];

    while (testCases--) {
        int n;
        int minPosition = INT_MAX; // Initialize minPosition with a very large value
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            posArr[i] = -1;
            countArr[i] = 0;
            visited[i] = false;
            indices[i].clear();
        }

        for (int i = 1; i <= n; ++i) {
            posArr[arr[i]] = i;
            indices[arr[i]].push_back(i);    
        }

        for (int i = 1; i <= n; ++i) {
            if (posArr[i] != -1) {
                countArr[posArr[i]]++;
                minPosition = min(minPosition, posArr[i]);
            }
        }

        vector<int> result;

        for (int i = 1; i <= n;) {
            if (i == minPosition) {
                result.push_back(arr[i]); 
                countArr[posArr[arr[i]]]--;

                while (countArr[minPosition] == 0 && minPosition <= n) 
                    minPosition++;

                i++;
            } else {
                if (result.size() % 2 == 0) {
                    int maxElement = 0;
                    for (int j = i; j <= min(minPosition, n); ++j) {
                        if (!visited[j]) 
                            maxElement = max(maxElement, arr[j]);
                    }
                    for (int j = i; j <= min(minPosition, n); ++j) {
                        if (arr[j] == maxElement) {
                            i = j + 1;
                            break;
                        }
                    }
                    if (maxElement == 0) 
                        break;

                    result.push_back(maxElement);
                    countArr[posArr[maxElement]]--;

                    while (countArr[minPosition] == 0 && minPosition <= n) 
                        minPosition++;
                } else {
                    int minElement = INT_MAX;
                    for (int j = i; j <= min(minPosition, n); ++j) {
                        if (!visited[j]) 
                            minElement = min(minElement, arr[j]);
                    }
                    for (int j = i; j <= min(minPosition, n); ++j) {
                        if (arr[j] == minElement) {
                            i = j + 1;
                            break;
                        }
                    }
                    if (minElement == INT_MAX) 
                        break;

                    result.push_back(minElement);
                    countArr[posArr[minElement]]--;

                    while (countArr[minPosition] == 0 && minPosition <= n) 
                        minPosition++;
                }
            }

            for (int index : indices[result.back()]) 
                visited[index] = true;
        }

        cout << result.size() << endl;
        for (int value : result) 
            cout << value << ' ';
        cout << endl;
    }

    return 0;
}
