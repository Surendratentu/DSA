#include <iostream>
#include <vector>
using namespace std;

/*
===================================================
 Find Kth Largest Element using Partial Bubble Sort

 Description:
 - The goal is to find the Kth largest element in an unsorted array.
 - This solution uses a partial Bubble Sort to sort the largest elements
   to the end of the array.
 - After k passes of Bubble Sort, the Kth largest element will be at
   index (n - k), where n is the size of the array.

 Time Complexity:
 - Worst Case: O(k * n) 
   (k passes, each pass with up to (n - 1) comparisons)
 - Best Case: O(k * n) even if partially sorted

 Space Complexity:
 - O(1) – In-place sorting

 Stability:
 - Bubble Sort is stable, but stability isn't important for finding Kth element.

 In-place:
 - Yes – only uses constant extra space.

 Limitations:
 - Inefficient for large arrays or large values of k.
 - Better alternatives: Min-Heap (O(n log k)), QuickSelect (average O(n))

===================================================
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(nums[j] > nums[j + 1]) {
                    // Swap adjacent elements if in wrong order
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        // Kth largest is now at index (n - k)
        return nums[n - k];
    }
};

// Helper function to print an array (for debugging)
void printArray(const vector<int>& arr) {
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the implementation
int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Solution sol;
    int result = sol.findKthLargest(nums, k);

    cout << "Original Array: ";
    printArray(nums); // Shows the modified array after sorting

    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
