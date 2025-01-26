#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 400000;

int arr[MAX_SIZE], countArr[MAX_SIZE], posArr[MAX_SIZE];
vector<int> indices[MAX_SIZE];

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        int minPosition = INT_MAX;  // Initialize minPosition with a very large value
        cin >> n;

        // Reset arrays and vectors for each test case
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            posArr[i] = -1;
            countArr[i] = 0;
            indices[i].clear();
        }

        // Store positions of each element and fill indices array with the indices
        for (int i = 1; i <= n; ++i) {
            posArr[arr[i]] = i;
            indices[arr[i]].push_back(i);    
        }

        // Calculate the minimum position for the initial setup
        for (int i = 1; i <= n; ++i) {
            if (posArr[i] != -1) {
                countArr[posArr[i]]++;
                minPosition = min(minPosition, posArr[i]);
            }
        }

        vector<int> result;

        for (int i = 1; i <= n;) {
            if (i == minPosition) {
                // If current index matches minPosition, add it to the result
                result.push_back(arr[i]); 
                countArr[posArr[arr[i]]]--;

                while (countArr[minPosition] == 0 && minPosition <= n) 
                    minPosition++;

                i++;
            } else {
                if (result.size() % 2 == 0) {
                    // For even-sized result, find the maximum element between i and minPosition
                    int maxElement = 0;
                    for (int j = i; j <= min(minPosition, n); ++j) {
                        if (countArr[j] > 0)  // Only consider unvisited indices
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
                    // For odd-sized result, find the minimum element between i and minPosition
                    int minElement = INT_MAX;
                    for (int j = i; j <= min(minPosition, n); ++j) {
                        if (countArr[j] > 0)  // Only consider unvisited indices
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

            // Mark all indices in the test of the last element in result as visited
            for (int index : indices[result.back()]) 
                countArr[index] = 0;  // Effectively "mark" as visited by setting count to 0
        }

        // Output the result
        cout << result.size() << endl;
        for (int value : result) 
            cout << value << ' ';
        cout << endl;
    }

    return 0;
}
