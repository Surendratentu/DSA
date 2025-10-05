#include <bits/stdc++.h>
using namespace std;

/*
  Function: findDuplicate
  Purpose:
      Finds the single duplicate number in an array containing n+1 integers 
      where each integer is between 1 and n (inclusive).
  
  Approach (Cyclic Sort):
      1. Each number should ideally be placed at index nums[i] - 1.
      2. While iterating, if nums[i] is not at its correct index, 
         and nums[i] != nums[nums[i] - 1], swap them.
      3. If nums[i] == nums[nums[i] - 1], it means a duplicate is found.
  
  Example:
      Input:  [3, 1, 3, 4, 2]
      After sorting: duplicate found = 3
  
  Time Complexity:  O(n)
      Each element is swapped at most once.

  Space Complexity: O(1)
      In-place swaps, no extra data structures used.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        while (i < n) {
            int correctidx = nums[i] - 1;

            if (nums[i] != nums[correctidx]) {
                swap(nums[i], nums[correctidx]);
            } else {
                if (i != correctidx) 
                    return nums[i];  // found duplicate
                i++;
            }
        }

        return -1; // shouldn't reach here if input guarantees one duplicate
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 1, 3, 4, 2};
    cout << "Duplicate Number: " << s.findDuplicate(nums);
    return 0;
}
