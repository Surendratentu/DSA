#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
        Function: totalSuccessfulPairs
        --------------------------------
        Purpose:
        Given a single spell and a sorted list of potions, this function counts
        how many potions form a successful pair with the spell, i.e.,
        spell * potion >= success.

        Parameters:
        - spell: the current spell value
        - potions: vector of potion values (sorted)
        - success: the threshold value for a successful pair

        Approach:
        1. Use binary search to find the first potion that satisfies spell * potion >= success.
        2. All potions to the right of this index are automatically successful.
        3. Return the count of successful potions.

        Notes:
        - Cast to long long during multiplication to prevent integer overflow.
        - If no potion works, the count will correctly be 0.
    */
    int totalSuccessfulPairs(int spell, vector<int>& potions, long long success) {
        int low = 0, high = potions.size() - 1;
        int ans = potions.size(); // Default: assume no successful potion

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long product = (long long)spell * potions[mid]; // Prevent overflow

            if (product >= success) {
                ans = mid;       // Found a potion that works
                high = mid - 1;  // Check if there is an earlier successful potion
            } else {
                low = mid + 1;   // Potion too small, check right half
            }
        }

        // Total successful potions = total potions - index of first successful potion
        return potions.size() - ans;
    }

    /*
        Function: successfulPairs
        ---------------------------
        Purpose:
        For each spell in the input vector, calculates the number of potions
        that form a successful pair with it and stores the count in the same
        spell's position.

        Steps:
        1. Sort the potions array to allow binary search.
        2. For each spell, call totalSuccessfulPairs to compute the count.
        3. Overwrite the spell with its successful pair count.
        4. Return the modified spells vector.
        
        Complexity:
        - Sorting: O(m log m), where m = number of potions
        - Binary search per spell: O(n log m), where n = number of spells
        - Total: O(n log m + m log m)
    */
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end()); // Sort potions for binary search

        for (int i = 0; i < spells.size(); i++) {
            int count = totalSuccessfulPairs(spells[i], potions, success);
            spells[i] = count; // Store result in place
        }

        return spells; // Return vector of successful pair counts
    }
};

// Driver code to test the solution
int main() {
    Solution sol;

    vector<int> spells = {10, 20, 30};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 50;

    vector<int> result = sol.successfulPairs(spells, potions, success);

    cout << "Successful pairs for each spell: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
