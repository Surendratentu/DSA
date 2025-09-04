/*
LeetCode Problem: Binary Search
Description: Given a sorted array of integers and a target value, 
return the index of the target if it exists, otherwise return -1.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int BinarySearch(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << sol.BinarySearch(nums, target) << endl;  
    return 0;
}
