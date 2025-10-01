#include <iostream>
#include <vector>
using namespace std;

/*
==============================================
 Selection Sort Algorithm

 Description:
 - Selection Sort is a comparison-based sorting algorithm.
 - It repeatedly finds the minimum element from the unsorted part
   and moves it to the beginning.

 How it works:
 - For each index i from 0 to n-1:
     - Find the minimum element from index i to end.
     - Swap it with the element at index i.

 Time Complexity:
 - Best Case:    O(n^2)
 - Average Case: O(n^2)
 - Worst Case:   O(n^2)

 Space Complexity:
 - O(1) (In-place sorting)

 Stability:
 - Not Stable (because equal elements may be swapped, changing their order)

 In-place:
 - Yes (does not require extra space)

==============================================
*/

class Solution {
public:
    // Function to find the index of the minimum element from 'start' to end
    int getMinIndex(vector<int>& arr, int start) {
        int minIndex = start;
        for(int i = start; i < arr.size(); i++) {
            if(arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    }

    // Function to perform selection sort
    void selectionSort(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            int minIndex = getMinIndex(arr, i);
            if(i != minIndex) {
                // Swap elements
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }
};

// Function to print the array
void printArray(const vector<int>& arr) {
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function with example
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    printArray(arr);

    Solution sorter;
    sorter.selectionSort(arr);

    cout << "Sorted Array:   ";
    printArray(arr);

    return 0;
}

