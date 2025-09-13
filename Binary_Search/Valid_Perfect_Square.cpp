/*
LeetCode 367: Valid Perfect Square

Question:
Given a positive integer num, return true if num is a perfect square, otherwise return false.
Do not use built-in functions like sqrt.

Approach:
- Use binary search between 1 and num.
- Compute mid * mid (casted to long long to avoid overflow).
- If mid * mid == num → return true.
- If mid * mid < num → search in right half.
- Else → search in left half.
- If no exact square found, return false.

Time Complexity: O(log n)  
    - Each step halves the search range.  
Space Complexity: O(1)  
    - Only a few variables used (low, high, mid).  
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long square = (long long)mid * mid;

            if (square == num) return true;
            else if (square > num) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test cases
    int nums[] = {1, 4, 14, 16, 25, 26};
    for (int n : nums) {
        cout << "Is " << n << " a perfect square? "
             << (sol.isPerfectSquare(n) ? "Yes" : "No") << endl;
    }

    return 0;
}
