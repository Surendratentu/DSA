#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

/*
Painter's Partition Problem

Description:
- Given A painters and an array C of board lengths.
- Each painter paints contiguous boards only.
- Painting 1 unit of board takes B units of time.
- Goal: Minimize the maximum time taken by any painter to paint the boards.

Input:
- A : Number of painters
- B : Time per unit length
- C : Vector of board lengths

Output:
- Minimum time required to paint all boards modulo 10000003

Approach:
- Binary Search on answer:
    - Low bound = max board length * B
    - High bound = sum of board lengths * B
- Check if a given mid time is possible with available painters:
    - Traverse boards, assign to current painter until mid exceeded
    - Move to next painter if exceeded
    - If painters exceed A, mid is not feasible
- Return the minimum feasible mid modulo 10000003

Time Complexity: O(N * log(sum * B))
Space Complexity: O(1)

Example:

Input: 
A = 2, B = 5, C = {1, 10}

Step 1: Compute bounds
- max board length = 10 -> low = 10*5 = 50
- sum boards = 11 -> high = 11*5 = 55

Step 2: Binary Search
- mid = 52 -> Painter1 paints 1*5=5, next board 10*5=50 -> exceeds 52, Painter2 takes 10*5=50 -> possible
- mid = 50 -> Painter1 paints 1*5=5, next board 10*5=50 -> exceeds 50, Painter2 takes 50 -> possible
- mid = 49 -> Painter1 paints 1*5=5, next board 50 -> exceeds 49, Painter2 paints 50 -> exceeds max -> not feasible

Step 3: Minimum feasible mid = 50

Output: 50 % 10000003 = 50
*/

class Solution {
private:
    bool CanPaints(long long mid, int painters, int units, vector<int>& C) {
        int paintersUsed = 1;
        long long unitsPainted = 0;
        int i = 0;

        while (i < C.size()) {
            long long work = (long long)C[i] * units;

            if (work > mid) return false; // single board bigger than mid

            if (unitsPainted + work > mid) {
                paintersUsed++;
                unitsPainted = 0;
                if (paintersUsed > painters) return false;
            } else {
                unitsPainted += work;
                i++;
            }
        }
        return paintersUsed <= painters;
    }

public:
    int paint(int A, int B, vector<int> &C) {
        long long sum = 0, maxi = -1;
        for (int i = 0; i < C.size(); i++) {
            maxi = max(maxi, (long long)C[i]);
            sum += C[i];
        }

        long long low = maxi * B, high = sum * B, ans = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (CanPaints(mid, A, B, C)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans % 10000003;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int A = 2; // painters
    int B = 5; // time per unit
    vector<int> C = {1, 10}; // board lengths

    cout << "Minimum time to paint boards: " << sol.paint(A, B, C) << endl;

    // Test Case 2
    A = 3;
    B = 1;
    C = {10, 20, 30, 40};
    cout << "Minimum time to paint boards: " << sol.paint(A, B, C) << endl;
    return 0;
}
