#include <bits/stdc++.h>
using namespace std;

/*
    Program: Find Number of Rotations in a Rotated Sorted Array
    ----------------------------------------------------------------
    Problem:
    Given a sorted and rotated array, determine how many times it has been rotated.
    This is equivalent to finding the index of the minimum element.

    Approach:
    1. If the first element is less than or equal to the last element, the array
       is already sorted, so the number of rotations is 0.
    2. Otherwise, use Binary Search:
       - Find the mid index.
       - If the subarray from low to high is sorted, the minimum is at 'low'.
       - If the left half is sorted and mid > high, search in the right half by
         moving low = mid + 1.
       - Otherwise, search in the left half by moving high = mid.
    3. Loop until low == high, which is the index of the minimum element.
    
    Time Complexity: O(log n)
    Space Complexity: O(1)

    Example:
    Input: nums = [3,4,5,1,2]
    Output: 3
    Explanation: The array is rotated 3 times.
*/

class Solution {
public:
    int findKRotation(vector<int> &nums) {
        int n = nums.size();
        if (nums[0] <= nums[n - 1])
            return 0;

        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[low] <= nums[high])
                return low;
            if (nums[low] <= nums[mid] && nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {3,4,5,1,2},
        {15,18,2,3,6,12},
        {1,2,3,4,5},
        {7},
        {5,6,1,2,3,4}
    };

    for (auto &nums : testCases) {
        cout << "Array: ";
        for (int num : nums) cout << num << " ";
        cout << "\nRotations: " << sol.findKRotation(nums) << "\n\n";
    }

    return 0;
}