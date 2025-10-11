#include <bits/stdc++.h>
using namespace std;

// Function to check if the array is sorted and rotated.
// A sorted and rotated array can be obtained by rotating a non-decreasing sorted array.
// Example: [3,4,5,1,2] is a rotation of [1,2,3,4,5].
//
// Time Complexity: O(n) - single traversal to count disorder points.
// Space Complexity: O(1) - constant extra space.

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) count++;
        }
        if (nums[n - 1] > nums[0]) count++;
        return count <= 1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 4, 5, 1, 2}; // Rotated sorted array
    vector<int> nums2 = {1, 2, 3, 4, 5}; // Sorted but not rotated
    vector<int> nums3 = {2, 1, 3, 4};    // Not sorted and rotated

    cout << boolalpha; // Print true/false instead of 1/0

    cout << "Array 1: [3, 4, 5, 1, 2] -> " << sol.check(nums1) << endl;
    cout << "Array 2: [1, 2, 3, 4, 5] -> " << sol.check(nums2) << endl;
    cout << "Array 3: [2, 1, 3, 4] -> " << sol.check(nums3) << endl;

    return 0;
}
