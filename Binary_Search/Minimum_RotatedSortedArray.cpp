#include <bits/stdc++.h>
using namespace std;

/*
    Problem:
    ----------
    Given a rotated sorted array without duplicates, 
    find the minimum element.

    Example:
    Input: [4,5,6,7,0,1,2]
    Output: 0

    Key Idea:
    ----------
    1. If the array is already sorted (nums[0] < nums[n-1]),
       then the minimum is simply nums[0].
    
    2. Otherwise, use binary search:
       - Keep two pointers: low and high.
       - Find mid = (low + high) / 2.
       - If the left part (nums[low] to nums[mid]) is sorted 
         and nums[mid] >= nums[high], then the minimum lies 
         in the right half → move low = mid + 1.
       - Otherwise, the minimum is in the left half → move high = mid.

    3. Continue until low == high, 
       then nums[low] is the minimum element.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        // Case 1: If array is already sorted (no rotation)
        if (nums[0] < nums[nums.size() - 1]) 
            return nums[0]; 

        int low = 0, high = nums.size() - 1;

        // Binary search
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If subarray from low to high is sorted
            if (nums[low] < nums[high]) 
                return nums[low];

            // If left half is sorted and mid >= high → search right half
            if (nums[low] <= nums[mid] && nums[mid] >= nums[high]) 
                low = mid + 1;
            else 
                high = mid; // search left half
        }
        return nums[low]; 
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums = {4,5,6,7,0,1,2};

    cout << "Minimum element in rotated sorted array: " 
         << sol.findMin(nums) << endl;

    return 0;
}
