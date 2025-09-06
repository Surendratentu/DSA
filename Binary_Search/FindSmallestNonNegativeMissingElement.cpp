/*
LeetCode Problem: Find Smallest Missing Non-Negative Element
Description: Given a sorted array of distinct non-negative integers, 
return the smallest non-negative integer that is missing from the array.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int FindSmallestMissingElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int MissingElement = nums.size();
        if (nums[0] != 0) return 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] != mid) {
                MissingElement = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return MissingElement;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 2, 6, 9, 11, 15};

    cout << sol.FindSmallestMissingElement(nums) << endl;  // Output: 3

    return 0;
}
