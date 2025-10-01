#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @brief Computes the integer nth root of m using binary search.
     *
     * Finds an integer x such that x^n = m if it exists.
     * If no such integer exists, returns -1.
     *
     * Uses binary search between 1 and m to find the root.
     * Uses a custom power function to safely compute mid^n without floating point errors or overflow.
     *
     * @param n The degree of the root.
     * @param m The number to find the root of.
     * @return The integer nth root if exists, otherwise -1.
     *
     * Time Complexity:
     * - Binary search runs in O(log m) iterations.
     * - Each iteration calls power() which runs in O(log n) using fast exponentiation.
     * - Overall time complexity: O(log m * log n)
     *
     * Space Complexity:
     * - Uses constant extra space: O(1)
     */
    int NthRoot(int n, int m) {
        long long low = 1, high = m;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = power(mid, n, m);

            if (val == m) {
                return (int)mid;
            } else if (val == -1 || val > m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;  // no exact integer nth root found
    }

    /**
     * @brief Computes base^exponent safely using fast exponentiation.
     *
     * Multiplies carefully and stops early if result would overflow limit.
     * Returns -1 if overflow occurs.
     *
     * @param base The base number.
     * @param exponent The exponent.
     * @param limit The upper limit to avoid overflow.
     * @return base^exponent if <= limit, otherwise -1.
     */
    long long power(long long base, int exponent, long long limit) {
        long long result = 1;

        while (exponent > 0) {
            if (exponent & 1) {
                if (result > limit / base) return -1;  // overflow detected
                result *= base;
            }
            exponent >>= 1;
            if (exponent > 0) {
                if (base > limit / base) return -1;    // overflow detected
                base *= base;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    int n = 3;
    int m = 27;

    int root = sol.NthRoot(n, m);
    if (root != -1) {
        cout << "The " << n << "th root of " << m << " is " << root << "." << endl;
    } else {
        cout << "No integer " << n << "th root exists for " << m << "." << endl;
    }

    return 0;
}
