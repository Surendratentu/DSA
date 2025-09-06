/*
LeetCode Problem: Find First and Last Position of Element in Sorted Array
Description: 
Given a sorted array 'nums' and a target value, find the first and last index 
of the target in the array. If the target is not present, return [-1, -1].

Approach:
- Use binary search to find the lower bound (first occurrence of target).
- Use binary search to find the upper bound (first element greater than target).
- Last occurrence = upper bound - 1.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Find first element greater than target (upper bound)
    int FindUpperBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int UpperBound = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target) {
                UpperBound = mid;    // potential upper bound
                high = mid - 1;      // search left
            } else {
                low = mid + 1;       // search right
            }
        }
        return UpperBound;
    }

    // Find first element >= target (lower bound)
    
    int FindLowerBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int LowerBound = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                LowerBound = mid;   // potential lower bound
                high = mid - 1;     // search left
            } else {
                low = mid + 1;      // search right
            }
        }
        return LowerBound;
    }

    // Find first and last positions of target
    vector<int> FindFirstAndLastElement(vector<int>& nums, int target) {
        int lb = FindLowerBound(nums, target);  // first occurrence
        if (lb == -1 || nums[lb] != target)     // target not found
            return {-1, -1};

        int ub = FindUpperBound(nums, target);  // first element > target
        return {lb, ub - 1};                    // last occurrence = ub - 1
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    vector<int> result = sol.FindFirstAndLastElement(nums, target);
    cout << "First and Last Occurrence: [" << result[0] << ", " << result[1] << "]" << endl; // Output: [1,3]

    return 0;
}
