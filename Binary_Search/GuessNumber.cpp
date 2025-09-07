#include <iostream>
using namespace std;

/*
    Problem:
    ----------
    We need to guess a number that is chosen by the system within a range [1, n].
    A helper function `guess(int num)` is provided:
        - Returns 0 if num is the correct number
        - Returns -1 if the chosen number is lower than num
        - Returns 1 if the chosen number is higher than num

    Approach:
    ----------
    - Use Binary Search between low = 1 and high = n.
    - At each step, calculate mid = low + (high - low) / 2
        - If guess(mid) == 0 → we found the number.
        - If guess(mid) == -1 → the chosen number is smaller, move search space to left (high = mid - 1).
        - If guess(mid) == 1 → the chosen number is larger, move search space to right (low = mid + 1).
    - Repeat until the correct number is found.

    Time Complexity:
    ----------------
    -  O(log n)
    - Space Complexity → O(1), constant extra space.
*/

int pick = 25;  // Let's assume the picked number is 37
int guess(int num) {
    if (num == pick) return 0;
    else if (num > pick) return -1;
    else return 1;
}

int guessNumber(int n) {
    int low = 1, high = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (guess(mid) == 0) return mid;
        else if (guess(mid) == -1) high = mid - 1;
        else low = mid + 1;
    }
    return -1;  // Should never reach here if pick ∈ [1,n]
}

int main() {
    int n = 100;  // Search space: 1 to 100
    cout << "Picked number is: " << guessNumber(n) << endl;
    return 0;
}
