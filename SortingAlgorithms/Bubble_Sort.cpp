#include <iostream>
#include <vector>
using namespace std;

/*
==============================================
 Bubble Sort Algorithm

 Description:
 - Bubble Sort is a simple comparison-based sorting algorithm.
 - In each pass, it repeatedly steps through the array, compares
   adjacent elements, and swaps them if they are in the wrong order.
 - The largest elements "bubble up" to the end.

 Optimized Version:
 - Uses a boolean flag `isSwaped` to stop early if the array is
   already sorted, improving best-case performance.

 Time Complexity:
 - Best Case:    O(n)        (when the array is already sorted)
 - Average Case: O(n^2)
 - Worst Case:   O(n^2)

 Space Complexity:
 - O(1) (In-place sorting)

 Stability:
 - Stable (equal elements maintain their relative order)

 In-place:
 - Yes

==============================================
*/

class Solution {
public:
    // Function to perform bubble sort
    void bubbleSort(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            bool isSwaped = false;

            // Last i elements are already in place
            for(int j = 0; j < arr.size() - i - 1; j++) {
                if(arr[j] > arr[j + 1]) {
                    // Swap adjacent elements
                    swap(arr[j], arr[j + 1]);
                    isSwaped = true;
                }
            }

            // If no swaps were made in this pass, the array is sorted
            if(!isSwaped) return;
        }
    }
};

// Helper function to print an array
void printArray(const vector<int>& arr) {
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the bubble sort
int main() {
    vector<int> arr = {5, 1, 4, 2, 8};

    cout << "Original Array: ";
    printArray(arr);

    Solution sorter;
    sorter.bubbleSort(arr);

    cout << "Sorted Array:   ";
    printArray(arr);

    return 0;
}
