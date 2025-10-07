#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
      Function: merge
      ----------------
      This function merges two sorted arrays into one sorted array in non-decreasing order.

      Parameters:
      nums1: vector<int>&  -> The first sorted array with extra space at the end to hold elements of nums2.
      m: int               -> The number of initialized elements in nums1.
      nums2: vector<int>&  -> The second sorted array.
      n: int               -> The number of initialized elements in nums2.

      Approach:
      - Start merging from the end of both arrays to avoid overwriting elements in nums1.
      - Use three pointers:
          i → last valid element in nums1
          j → last element in nums2
          k → last position in nums1 (including extra space)
      - Compare elements from the back and place the larger one at position k.
      - Continue until one of the arrays is fully processed.
      - If elements remain in nums2, copy them into nums1.

      Example:
      nums1 = [1, 2, 3, 0, 0, 0], m = 3
      nums2 = [2, 5, 6], n = 3
      After merging → nums1 = [1, 2, 2, 3, 5, 6]

      Time Complexity:
      O(m + n) → Each element from both arrays is compared and placed once.

      Space Complexity:
      O(1) → In-place merging without using extra space.
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = nums1.size() - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j])
                nums1[k--] = nums2[j--];
            else
                nums1[k--] = nums1[i--];
        }
        while (i >= 0) nums1[k--] = nums1[i--];
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    s.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    return 0;
}
