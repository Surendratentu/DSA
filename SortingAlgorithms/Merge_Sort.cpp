#include <iostream>
#include <vector>

using namespace std;

/*
 * Merge two sorted subarrays arr[left..mid] and arr[mid+1..right]
 */
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // size of first subarray
    int n2 = right - mid;    // size of second subarray

    // Temporary arrays
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Merge temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements if any
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

/*
 * Recursive Merge Sort function
 */
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return; // base case: 1 element

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);       // sort first half
    mergeSort(arr, mid + 1, right);  // sort second half
    merge(arr, left, mid, right);    // merge sorted halves
}

/*
 * Utility function to print the array
 */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

/*
 * Main function
 */
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}

/*
 * Time Complexity:
 *   - Best, Average, Worst: O(n log n)
 * Space Complexity:
 *   - O(n) due to temporary arrays for merging
 * Stability:
 *   - Merge Sort is stable (preserves relative order of equal elements)
 */
