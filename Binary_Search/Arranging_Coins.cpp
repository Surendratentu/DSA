/*
LeetCode 441: Arranging Coins

Question:
You have n coins and you want to build a staircase with them.
The k-th row of the staircase must have exactly k coins.
Given n, return the total number of complete rows that can be formed.

Approach:
- The total coins needed to fill k rows is k*(k+1)/2 (triangular number).
- Use binary search on k in the range [1, n].
- If k*(k+1)/2 <= n → store k in ans and move right (low = mid + 1).
- If k*(k+1)/2 > n → move left (high = mid - 1).
- Finally return ans (last valid full row count).

Time Complexity: O(log n)  
    - Binary search halves the range each step.  
Space Complexity: O(1)  
    - Only variables for low, high, mid, ans.  
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1, high = n, ans = 0;
        if (n == 1) return 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long coins = (long long)mid * (mid + 1) / 2;

            if (coins > n) {
                high = mid - 1;
            } else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test cases
    int nums[] = {1, 5, 8, 10, 15, 20};
    for (int n : nums) {
        cout << "n = " << n << " → complete rows = "
             << sol.arrangeCoins(n) << endl;
    }

    return 0;
}
