#include <bits/stdc++.h> // or you can include <iostream> + <vector>
using namespace std;

/*
 * Function: cyclic_sort
 * ---------------------
 * Sorts an array of size n containing numbers 1 to n using the Cyclic Sort algorithm.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
vector<int> cyclic_sort(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
        int correct_index = nums[i] - 1;

        // If element is not at its correct index, swap it
        if (nums[i] != nums[correct_index])
            swap(nums[i], nums[correct_index]);
        else
            i++; // move forward only when element is at the right place
    }
    return nums;
}

int main() {
    vector<int> nums = {3, 1, 5, 4, 2};
    vector<int> sorted = cyclic_sort(nums);

    for (int num : sorted) {
        cout << num << " ";
    }

    return 0;
}
