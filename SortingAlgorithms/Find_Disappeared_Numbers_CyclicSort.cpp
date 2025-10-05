#include <bits/stdc++.h>
using namespace std;

/*
  Function: findDisappearedNumbers
  Purpose:
      Finds all numbers missing from the array containing integers from 1 to n.
      Some numbers may be duplicated, some may be missing.

  Approach (Cyclic Sort):
      1. Place each number at its correct index: nums[i] → nums[i]-1.
      2. Skip numbers that are already at the correct index or duplicates.
      3. After rearranging, indices where nums[i] != i+1 indicate missing numbers.

  Example:
      Input:  [4,3,2,7,8,2,3,1]
      After sorting: [1,2,3,4,3,2,7,8]
      Missing numbers = [5,6]

  Time Complexity: O(n)
      - Each number swapped at most once.

  Space Complexity: O(1) extra
      - Output array not counted in extra space as required by problem.
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            int crtidx = nums[i] - 1;
            if (nums[i] != nums[crtidx]) {
                swap(nums[i], nums[crtidx]);
            } else {
                i++;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) ans.push_back(i + 1);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> missing = s.findDisappearedNumbers(nums);
    cout << "Missing Numbers: ";
    for (int x : missing) cout << x << " ";
    return 0;
}
