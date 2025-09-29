#include <bits/stdc++.h>
using namespace std;

/*
    Program: Search in a 2D Row-wise Sorted Matrix
    ----------------------------------------------------------------
    Problem:
    Given a 2D matrix where each row is sorted from left to right and the 
    first integer of each row is greater than the last integer of the previous row,
    determine if a target value exists in the matrix.

    Approach:
    1. Treat the matrix as a flattened 1D array of size n*m.
    2. Use binary search on indices from 0 to n*m-1.
    3. Convert mid index to 2D coordinates: row = mid / m, col = mid % m.
    4. Compare matrix[row][col] with target to move left or right in the search.
    5. Return true if found, otherwise false.

    Time Complexity: O(log(n*m))
    Space Complexity: O(1)

    Example:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n * m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / m, c = mid % m;
            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    cout << boolalpha; 
    cout << "Search 3: " << sol.searchMatrix(matrix, 3) << endl;
    cout << "Search 13: " << sol.searchMatrix(matrix, 13) << endl;

    return 0;
}
