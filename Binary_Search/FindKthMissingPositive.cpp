#include <bits/stdc++.h>
using namespace std;

/*
Problem:
---------
We are given a sorted array of positive integers `arr` (strictly increasing),
and an integer `k`. We need to find the k-th missing positive number that
does not appear in the array.

Example:
---------
arr = [2,3,4,7,11], k = 5
Output = 9

Time Complexity:
----------------
O(log n), where n = arr.size(), because we are applying binary search.

Space Complexity:
-----------------
O(1), since we are only using a few extra variables.
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 1, high = arr.size(), largeEl = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            largeEl = arr[mid - 1] - mid;
            if (largeEl < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return k + high;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << "The " << k << "-th missing positive number is: "
         << sol.findKthPositive(arr, k) << endl;

    return 0;
}
