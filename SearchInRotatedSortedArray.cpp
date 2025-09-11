#include <bits/stdc++.h>
using namespace std;

/*
Problem:
---------
Search an element in a rotated sorted array.
The array was originally sorted in ascending order but then rotated
at some unknown pivot. You need to return the index of the target element
if found, otherwise return -1.

Example:
---------
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Approach (Binary Search in Rotated Sorted Array):
-------------------------------------------------
1. Use binary search with two pointers: low and high.
2. Find mid = low + (high - low) / 2.
3. If nums[mid] == target → return mid.
4. Otherwise, determine which half is sorted:
   - If nums[low] <= nums[mid], then the left half is sorted.
     * If target lies in [nums[low], nums[mid]) → search left half.
     * Else → search right half.
   - Else the right half is sorted.
     * If target lies in (nums[mid], nums[high]] → search right half.
     * Else → search left half.
5. Continue until low > high. If not found, return -1.

Time Complexity:
----------------
O(log n) → Because binary search halves the search space each step.

Space Complexity:
-----------------
O(1) → Constant extra space, no recursion or auxiliary data structures.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            
            // Left half sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } 
            // Right half sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Driver code
int main() {
    Solution obj;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = obj.search(nums, target);

    if (result != -1) 
        cout << "Element found at index: " << result << endl;
    else 
        cout << "Element not found in the array." << endl;

    return 0;
}
