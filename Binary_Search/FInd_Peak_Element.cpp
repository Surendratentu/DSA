#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find Peak Element
- Given an integer array nums, find a peak element, and return its index.
- A peak element is an element that is strictly greater than its neighbors.
- nums[-1] and nums[n] are considered -∞.
- You may return any peak if multiple exist.
- Must run in O(log n) time.

Example:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and its index is 2.
*/

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 1) return 0; // single element is a peak
    if (nums[0] > nums[1]) return 0; // first element peak
    if (nums[n - 1] > nums[n - 2]) return n - 1; // last element peak
    
    int low = 1, high = n - 2; // exclude edges since already checked
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
            return mid; // found peak
        } 
        else if (nums[mid - 1] > nums[mid]) {
            high = mid - 1; // peak is on left
        } 
        else {
            low = mid + 1; // peak is on right
        }
    }
    
    return -1; // should never reach here
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};

    cout << "Peak index in nums1: " << findPeakElement(nums1) << endl; // Expected: 2
    cout << "Peak index in nums2: " << findPeakElement(nums2) << endl; // Expected: 1 or 5

    return 0;
}
