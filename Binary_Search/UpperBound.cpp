/*
Problem: Upper Bound in Sorted Array
Description: Given a sorted array 'nums' and a target value,
find the index of the first element > target. Return -1 if no such element exists.

Time Complexity: O(log n),
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int FindUpperBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int UpperBound = -1;

    if (nums.empty()) return UpperBound;          
    if (nums[0] > target) return 0;     
    if(target>=nums[nums.size()-1]) return UpperBound;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > target) {
            UpperBound = mid;   
            high = mid - 1;     
        } else {
            low = mid + 1;     
        }
    }

    return UpperBound;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3, 5, 5};
    int target = 6;

    cout << "Upper bound of " << target << " is at index "
         << FindUpperBound(nums, target) << endl;

    return 0;
}
