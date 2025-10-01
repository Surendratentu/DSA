#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @brief Checks if it's possible to ship all packages within the given number of days,
     *        using the specified maximum ship capacity.
     *
     * @param capacity Maximum capacity of the ship per day.
     * @param weights Array of package weights.
     * @param days Maximum number of days allowed to ship all packages.
     * @return true if possible to ship within given days, false otherwise.
     */
    bool canShipInDays(int capacity, const vector<int>& weights, int days) {
        int dayCount = 1;
        int currentLoad = 0;

        for (int weight : weights) {
            if (weight > capacity) {
                return false; // Can't ship this package
            }

            if (currentLoad + weight <= capacity) {
                currentLoad += weight;
            } else {
                dayCount++;
                currentLoad = weight;

                if (dayCount > days) {
                    return false;
                }
            }
        }

        return true;
    }

    /**
     * @brief Finds the minimum ship capacity needed to ship all packages within the given days.
     *
     * Uses binary search between max(weights) and sum(weights) to minimize capacity.
     *
     * @param weights Vector of package weights.
     * @param days Maximum number of days allowed to ship all packages.
     * @return Minimum required ship capacity.
     *
     * Time Complexity: O(N * log(S)), where N = number of packages, S = sum of weights
     * Space Complexity: O(1)
     */
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = *max_element(weights.begin(), weights.end());
        int totalWeight = accumulate(weights.begin(), weights.end(), 0);

        int low = maxWeight;      // Minimum possible capacity
        int high = totalWeight;   // Maximum possible capacity
        int minCapacity = totalWeight;

        while (low <= high) {
            int midCapacity = low + (high - low) / 2;

            if (canShipInDays(midCapacity, weights, days)) {
                minCapacity = midCapacity;
                high = midCapacity - 1;
            } else {
                low = midCapacity + 1;
            }
        }

        return minCapacity;
    }
};
