/*
Problem:
--------
Given a sorted array `nums` and a target value, the function `solve` finds the
position where the target would be inserted or found, based on binary search.

Description:
--------
- If `target` is greater than the last element, return `nums.size()`.
- If `target` is smaller than the first element, return 0.
- Otherwise, perform binary search to find the correct index.

Approach:
---------
1. Initialize search range: low = 0, high = nums.size().
2. Use binary search to check the middle element.
3. If nums[mid] <= target, move right (low = mid + 1) and update ans = mid.
4. Otherwise, move left (high = mid - 1).
5. Finally, return ans + 1 (to give insertion position after the last occurrence).

Time Complexity:
----------------
- O(log n), because we are using binary search over the sorted array.

Space Complexity:
-----------------
- O(1), only a few variables are used.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums, int target) {
        int low = 0, high = nums.size();
        int ans = nums.size();

        if (target > nums[nums.size() - 1]) return ans;
        if (target < nums[0]) return 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 5;

    int result = sol.solve(nums, target);
    cout << "Result: " << result << endl;

    return 0;
}
