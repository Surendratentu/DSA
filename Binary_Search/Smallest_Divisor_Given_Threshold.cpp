#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @class Solution
 * @brief Solves the problem of finding the smallest divisor such that the sum of all
 *        ceiling divisions of array elements by the divisor does not exceed a threshold.
 *
 * -------------------------------
 * 🔹 Problem Statement:
 * Given a list of positive integers (`nums`) and an integer `threshold`, find the smallest
 * positive integer `divisor` such that the sum of all values ⌈nums[i] / divisor⌉ is less than
 * or equal to `threshold`. The ⌈ ⌉ symbol represents the ceiling function (rounding up).
 *
 * -------------------------------
 * 🔹 Approach:
 * - We use binary search to efficiently find the smallest valid divisor.
 * - The lowest possible divisor is 1.
 * - The highest possible divisor is the maximum value in the array.
 * - For each candidate divisor, we calculate the total sum of divisions:
 *     sum += (nums[i] + divisor - 1) / divisor
 *   (This avoids using floating-point operations.)
 * - If the sum is within the threshold, we try smaller divisors.
 * - Otherwise, we increase the divisor.
 *
 * -------------------------------
 * 🔹 Time Complexity:
 * - Let `n` = number of elements, `m` = max value in nums.
 * - Binary search takes O(log m), each check is O(n)
 * - Total Time: O(n * log m)
 *
 * 🔹 Space Complexity:
 * - Constant extra space: O(1) (excluding input)
 */
class Solution {
public:

    // Helper function to check if a given divisor is valid
    bool isDivisorValid(int divisor, const vector<int>& nums, int threshold) {
        int totalSum = 0;

        for (int num : nums) {
            totalSum += (num + divisor - 1) / divisor; // equivalent to ceil(num / divisor)

            if (totalSum > threshold) {
                return false;
            }
        }

        return true;
    }

    // Binary search to find the smallest valid divisor
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isDivisorValid(mid, nums, threshold)) {
                result = mid;       // Valid candidate, try to minimize
                right = mid - 1;
            } else {
                left = mid + 1;     // Not valid, need larger divisor
            }
        }

        return result;
    }
};

int main() {
    // Sample input
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    // Create an object of Solution class
    Solution solution;

    // Get and print the result
    int smallestDiv = solution.smallestDivisor(nums, threshold);
    cout << "Smallest Divisor: " << smallestDiv << endl;

    return 0;
}
