/*
Problem: Lower Bound in Sorted Array
Description: Given a sorted array 'nums' and a target value,
find the index of the first element ≥ target. Return -1 if no such element exists.

Time Complexity: O(log n),
Space Complexity: O(1)

*/
#include<iostream>
#include<vector>
using namespace std;


int FindLowerBound(vector<int>&nums,int target){
    int low=0,high=nums.size()-1;
    int LowerBound=-1;
    if(nums[0]>=target) return 0;  
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>=target){
         LowerBound=mid;
         high=mid-1;
        }
        else low=mid+1;
    }
    return LowerBound;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3, 5, 5};
    int target = 10;

    cout << "Lower bound of " << target << " is at index " 
         << FindLowerBound(nums, target) << endl;

    return 0;
}
