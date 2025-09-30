#include <bits/stdc++.h>
using namespace std;

/*
Problem: Koko Eating Bananas

Description:
- Koko loves bananas. There are n piles of bananas, piles[i] represents 
  the number of bananas in the i-th pile.
- Koko can decide an integer eating speed k (bananas per hour).
- Each hour, Koko chooses a pile and eats k bananas from it.
  - If the pile has less than k bananas, she eats all of them and stops for that hour.
- Goal: Find the minimum integer k such that Koko can eat all bananas within h hours.

Input:
- vector<int> piles : number of bananas in each pile
- int h : total hours available

Output:
- int : minimum eating speed k

Constraints:
- 1 <= piles.length <= 10^4
- 1 <= piles[i] <= 10^9
- 1 <= h <= 10^9

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Approach:
- Use **Binary Search** on possible eating speeds (k):
    - Low bound = 1
    - High bound = max(piles)
- For a given speed mid:
    - Calculate total hours needed to finish all piles at this speed
    - If total hours <= h, speed is feasible (try lower)
    - Else, need higher speed (increase mid)
- Continue until the minimum feasible speed is found.

Time Complexity: O(n * log(max(piles)))
Space Complexity: O(1)
*/

class Solution {
public:
    // Helper function to check if Koko can eat all bananas at speed 'mid'
    bool canEatAllBananasInMinSpeed(vector<int>& piles, int h, int mid) {
        long long totalHoursByKoko = 0;
        for(int i = 0; i < piles.size(); i++) {
            totalHoursByKoko += ceil((double)piles[i] / mid);
        }
        return totalHoursByKoko <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEl = 0;
        for(int i = 0; i < piles.size(); i++) {
            maxEl = max(maxEl, piles[i]);
        }

        int low = 1, high = maxEl, minSpeed = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canEatAllBananasInMinSpeed(piles, h, mid)) {
                minSpeed = mid; // feasible speed
                high = mid - 1; // try smaller
            } else {
                low = mid + 1; // need larger speed
            }
        }

        return minSpeed;
    }
};

int main() {
    Solution sol;

    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Minimum eating speed for test case 1: " 
         << sol.minEatingSpeed(piles1, h1) << endl; 

    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Minimum eating speed for test case 2: " 
         << sol.minEatingSpeed(piles2, h2) << endl; 

    return 0;
}
