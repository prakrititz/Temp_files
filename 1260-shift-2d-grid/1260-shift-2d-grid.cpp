
class Solution {
public:

    void reverse(vector<vector<int>>&grid ,int start, int end)
    {
        int n = grid[0].size();
        int low = start;
        int high = end;
        while(low<high)
        {
            swap(grid[high/n][high%n], grid[low/n][low%n]);
            high--;
            low++;
        }
    }
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int size  = m*n;
        // Calculate effective shift (in case k is greater than the total number of elements)
        int l = k % size;

        if (l == 0) {
            // No need to shift if l is 0
            return grid;
        } else 
        {
            reverse(grid, 0 , size-l-1);
            reverse(grid, size-l, size-1);
            reverse(grid, 0, size-1);
            return grid;
        }
    }
};