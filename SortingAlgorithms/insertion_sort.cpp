#include <bits/stdc++.h>
using namespace std;

/*
    Insertion Sort Algorithm
    ------------------------
    Description:
    - Insertion Sort is a simple comparison-based sorting algorithm.
    - It builds the sorted array one element at a time by inserting
      each element into its correct position among the already sorted elements.
    - This is similar to how people sort playing cards in their hands.

    How it Works:
    1. Start from the second element (index = 1), because the first element
       is already considered sorted.
    2. Pick the current element (currentElement).
    3. Compare it with elements to its left in the sorted portion.
    4. Shift all larger elements one step to the right.
    5. Insert currentElement at the correct position.
    6. Repeat until the entire array is sorted.

    Properties:
    - Time Complexity:
        Best Case (already sorted): O(n)
        Average Case: O(n^2)
        Worst Case (reverse sorted): O(n^2)
    - Space Complexity: O(1) → Only uses a few variables (in-place sorting).
    - Stable: Yes → Equal elements retain their relative order.
    - In-Place: Yes → Sorting happens within the given array.
*/

class Solution {
public:
    // Function to perform insertion sort
    void insertionSort(vector<int>& arr) {
        int n = arr.size();

        // Traverse elements from index 1 to n-1
        for (int i = 1; i < n; i++) {
            int currentElement = arr[i];  // element to be inserted
            int j = i - 1;                // pointer to the sorted portion

            /*
                Shift all elements greater than currentElement
                one position to the right, until the correct
                position is found.
            */
            while (j >= 0 && arr[j] > currentElement) {
                arr[j + 1] = arr[j];
                j--;
            }

            // Place currentElement into its correct position
            arr[j + 1] = currentElement;
        }
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<int> arr = {5, 3, 4, 1, 2};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    sol.insertionSort(arr);

    cout << "Sorted Array:   ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
