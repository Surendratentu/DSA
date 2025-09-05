#include <iostream>
#include <vector>
using namespace std;

int FindSmallestMissingElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    int MissingElement = nums.size();

    if (nums[0] != 0) return 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] != mid) {
            MissingElement = mid;
            high = mid - 1; // move left
        } else {
            low = mid + 1;  // move right
        }
    }

    return MissingElement;
}

int main() {
    vector<int> nums = {0, 1, 2, 3, 4, 6, 9, 11, 15};
    cout<<FindSmallestMissingElement(nums) << endl;
    return 0;
}
