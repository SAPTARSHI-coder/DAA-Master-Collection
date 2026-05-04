// ============================================================
// CASE STUDY 15: Trapping Rainwater Problem
// ============================================================
//
// PROBLEM STATEMENT:
//   Given a list of bar heights representing an elevation map,
//   calculate how much RAINWATER can be trapped after it rains.
//   Water rests between elevated bars, filling up to the level of
//   the SMALLER of the two surrounding tallest walls.
//
// REAL-LIFE INTERPRETATION:
//   - Urban planning: calculate flooded zones between buildings.
//   - Dam design: estimate water storage capacity.
//   - Land survey: estimate water collected in a valley between hills.
//
// ============================================================
// PATTERN RECOGNITION: MULTIPLE APPROACHES EXIST
// ============================================================
//
//  NAIVE (O(n^2)): For each position, scan left and right for max walls.
//
//  EFFICIENT APPROACH 1: PRECOMPUTE ARRAYS (O(n) time, O(n) space)
//    For each index i:
//      leftMax[i]  = max height from index 0 to i (highest wall on left)
//      rightMax[i] = max height from index i to n-1 (highest wall on right)
//    Water at i = max(0, min(leftMax[i], rightMax[i]) - height[i])
//
//  EFFICIENT APPROACH 2: TWO POINTERS (O(n) time, O(1) space)
//    Use two pointers (left and right) converging towards the center.
//    The side with the SMALLER max wall determines water level.
//    Eliminate whichever side is processed (similar to binary search logic).
//
//  WHY NOT GREEDY? Greedy chooses without looking back; water level
//                  depends on BOTH sides simultaneously.
//  WHY NOT DP? While Approach 1 resembles DP (precompute prefix/suffix),
//              the Two Pointer approach is more of a shrinking-window technique.
//
// CATEGORY: ARRAY TECHNIQUE (Prefix-Suffix / Two Pointers)
//
// ============================================================
// STEP-BY-STEP THINKING (Precompute Approach):
// ============================================================
//
//  Step 1: Build leftMax[] array (max height seen so far from left).
//  Step 2: Build rightMax[] array (max height seen so far from right).
//  Step 3: For each position i:
//            water[i] = max(0, min(leftMax[i], rightMax[i]) - height[i])
//  Step 4: Sum all water[i] for total trapped water.
//
// Example:
//   Heights: 0 1 0 2 1 0 1 3 2 1 2 1
//   Total trapped water = 6 units
//
// ============================================================

#include <iostream>
using namespace std;

// Function to compute trapped rainwater using Precomputed Arrays approach
int trappingRainwater(int height[], int n) {
    // Step 1: Build leftMax array
    // leftMax[i] = maximum height from height[0] to height[i]
    int leftMax[n];
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Step 2: Build rightMax array
    // rightMax[i] = maximum height from height[i] to height[n-1]
    int rightMax[n];
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // Step 3 & 4: Calculate water at each position and sum up
    int totalWater = 0;
    cout << "\nWater trapped at each position:" << endl;
    cout << "-------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        // Water level = min of the two surrounding highest walls
        int waterLevel = min(leftMax[i], rightMax[i]);

        // Water at this position = water level - bar height (can't be negative)
        int waterHere  = max(0, waterLevel - height[i]);
        totalWater    += waterHere;

        cout << "Position " << i << " (height=" << height[i]
             << ", leftMax=" << leftMax[i]
             << ", rightMax=" << rightMax[i]
             << ") -> Water: " << waterHere << endl;
    }

    return totalWater;
}

// OPTIMAL Two-Pointer approach: O(n) time, O(1) space
int trappingTwoPointer(int height[], int n) {
    int leftPtr  = 0;         // Left pointer starts at beginning
    int rightPtr = n - 1;     // Right pointer starts at end
    int leftWall = 0;         // Max wall height seen on left side
    int rightWall = 0;        // Max wall height seen on right side
    int totalWater = 0;

    while (leftPtr <= rightPtr) {
        // Process the side with the SMALLER wall (it determines water level)
        if (height[leftPtr] <= height[rightPtr]) {
            if (height[leftPtr] >= leftWall) {
                leftWall = height[leftPtr];  // Update left wall
            } else {
                // Water can be trapped here
                totalWater += leftWall - height[leftPtr];
            }
            leftPtr++;
        } else {
            if (height[rightPtr] >= rightWall) {
                rightWall = height[rightPtr];  // Update right wall
            } else {
                totalWater += rightWall - height[rightPtr];
            }
            rightPtr--;
        }
    }

    return totalWater;
}

int main() {
    int n;

    cout << "======================================================" << endl;
    cout << " CASE STUDY 15: Trapping Rainwater (Array Technique)" << endl;
    cout << "======================================================" << endl;
    cout << "\nEnter the number of bars: ";
    cin >> n;

    int height[n];

    cout << "Enter the height of each bar: ";
    for (int i = 0; i < n; i++) cin >> height[i];

    cout << "\nUsing Precomputed Arrays Method:" << endl;
    int result1 = trappingRainwater(height, n);
    cout << "\nTotal water trapped (Precompute): " << result1 << " units" << endl;

    int result2 = trappingTwoPointer(height, n);
    cout << "Total water trapped (Two Pointer): " << result2 << " units" << endl;

    return 0;
}

/*
============================
Time Complexity:
  Precompute approach:  O(n) -> Three passes through array
  Two Pointer approach: O(n) -> Single pass

Space Complexity:
  Precompute approach:  O(n) -> leftMax and rightMax arrays
  Two Pointer approach: O(1) -> Only 4 integer variables!

SIMILAR PROBLEMS (Same Prefix-Suffix or Two Pointer Pattern):
  1. Container With Most Water -> Two pointers, maximize area between bars
  2. Largest Rectangle in Histogram -> Stack-based approach for max area
  3. Product Array Except Self  -> Prefix and suffix product arrays

KEY INSIGHT FOR VIVA:
  "Water at position i is bounded by the MINIMUM of the tallest walls
   on BOTH SIDES. This is a prefix-suffix property -> precompute both."
============================
*/
