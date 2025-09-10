/*
Bubble Sort

Description:
Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
The pass through the list is repeated until the array is sorted.

Time Complexity:
- Best Case (Already Sorted): O(n) (with an optimization flag)
- Average Case: O(n²)
- Worst Case: O(n²)

Space Complexity:
- O(1) → In-place (no extra significant memory needed).

Stability:
- Stable → Equal elements maintain their original relative order.

In-place:
- Yes → Sorting happens by swapping within the array.
*/

function bubbleSort(arr) {
    let n = arr.length;
    for (let i = 0; i < n - 1; i++) {
        let isSwapped = false;

        // Last i elements are already in place
        for (let j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                let temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = true;
            }
        }

        // If no two elements were swapped, array is sorted
        if (!isSwapped) break;
    }
}

let arr = [64, 34, 25, 12, 22, 11, 90];
bubbleSort(arr);
console.log("Sorted array is:");
console.log(arr);
