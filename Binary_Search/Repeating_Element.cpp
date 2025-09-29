#include <bits/stdc++.h>
using namespace std;

/*
    Program: Find Repeating Element in a Sorted Array
    ----------------------------------------------------------------
    Problem:
    Array of size n contains numbers from 0 to n-2.
    Exactly one element is repeated twice. The array is sorted.
    Find the repeating element efficiently using binary search.

    Approach:
    1. Normally, nums[i] == i.
    2. When a number repeats, nums[i] > i starting from the duplicate.
    3. Use binary search to find the first index where nums[i] != i.
    4. Return nums[low] at the end.

    Time Complexity: O(log n)
    Space Complexity: O(1)

    Example:
    Input: nums = {0,1,2,3,3,4}
    Output: 3
*/

int findRepeatingElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] != mid) high = mid;
        else low = mid + 1;
    }
    return nums[low];
}

int main() {
    vector<int> nums = {0,1,2,3,3,4};
    cout << "Repeating element: " << findRepeatingElement(nums) << endl;
    return 0;
}
