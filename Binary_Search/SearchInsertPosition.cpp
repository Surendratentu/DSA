#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    Function: searchInsert
    ----------------------
    Problem:
    Given a sorted array of integers 'nums' and a target value 'target',
    find the index if the target is found. If not, return the index
    where it would be if it were inserted in order.

    Parameters:
    - nums: vector<int>&, a sorted array of integers
    - target: int, the value to search or insert

    Return Type:
    - int: the index of target if found, or the index where it should
      be inserted to maintain sorted order

    Approach:
    - Use Binary Search to efficiently locate the target or insertion index
    - Maintain 'low' and 'high' pointers to search range
    - If nums[mid] >= target, move 'high' left and update potential insert position
    - Otherwise, move 'low' right
    - Loop until low > high

    Time Complexity: O(log n), where n is the size of nums
    Space Complexity: O(1), constant extra space
    */
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int insertPosition = nums.size(); // Default insert at end if target is largest

        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevents overflow
            if (nums[mid] >= target) {
                insertPosition = mid; // Potential insert position
                high = mid - 1;       // Search left half
            } else {
                low = mid + 1;        // Search right half
            }
        }
        return insertPosition;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    cout << "Insert position: " << sol.searchInsert(nums, target) << endl; // Output: 2
    return 0;
}
