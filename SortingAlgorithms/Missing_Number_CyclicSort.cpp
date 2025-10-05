#include <bits/stdc++.h>
using namespace std;

/*
  Function: missingNumber
  Purpose:
      Finds the missing number in an array containing n distinct numbers 
      taken from the range [0, n].

  Approach (Cyclic Sort):
      1. For each element, place it at the index equal to its value 
         (i.e., value 3 should go to index 3).
      2. Ignore the number 'n' because it has no index in [0, n-1].
      3. After rearranging, the first index i where nums[i] != i 
         gives the missing number.
      4. If all numbers are at correct positions, then the missing 
         number is 'n'.

  Example:
      Input:  [3, 0, 1]
      After sorting in place: [0, 1, 3]
      Output: 2

  Time Complexity:  O(n)
      - Each element is swapped at most once.

  Space Complexity: O(1)
      - No extra data structures used; sorting is done in-place.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        // Step 1: Place numbers at their correct indices
        while (i < n) {
            int correctidx = nums[i];
            if (nums[i] < n && nums[i] != nums[correctidx]) {
                swap(nums[i], nums[correctidx]);
            } else {
                i++;
            }
        }

        // Step 2: Identify the missing number
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) return i;
        }

        // Step 3: If all are placed correctly, missing number is n
        return n;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 0, 1};
    cout << "Missing Number: " << s.missingNumber(nums);
    return 0;
}
