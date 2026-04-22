// Program: Box Stacking Problem (Dynamic Programming)
// What it does: Given a set of 3D boxes with height, width, and depth,
//               find the maximum height of a stack of boxes such that:
//               - A box can be placed ON TOP of another box ONLY IF
//                 BOTH its width AND depth are STRICTLY LESS than the box below.
//               - Each box can be used multiple times in different rotations.
//               - We consider all 3 ROTATIONS of each box.
//
// Key Insight: This reduces to the Longest Increasing Subsequence problem.
//
// Example Input:
//   3 boxes: (4,6,7), (1,2,3), (4,5,6)
// Expected Output: Maximum stack height

#include <iostream>
using namespace std;

// Structure to represent a box in one rotation
struct Box {
    int height;
    int width;  // width <= depth (we ensure width is always smaller)
    int depth;
};

// Function to sort boxes by their base area (width * depth) in decreasing order
void sortByBaseArea(Box boxes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            int area1 = boxes[j].width * boxes[j].depth;
            int area2 = boxes[j + 1].width * boxes[j + 1].depth;
            if (area1 < area2) {
                Box temp    = boxes[j];
                boxes[j]    = boxes[j + 1];
                boxes[j + 1] = temp;
            }
        }
    }
}

// Check if box 'top' can be placed on top of box 'bottom'
bool canPlace(Box top, Box bottom) {
    return top.width < bottom.width && top.depth < bottom.depth;
}

// Function to solve Box Stacking using DP (similar to LIS problem)
void boxStacking(int inputBoxes[][3], int n) {
    // Step 1: Generate all rotations of each box
    // Each box has 3 rotations (treating each face as the base)
    int totalBoxes = n * 3;
    Box boxes[totalBoxes];

    int idx = 0;
    for (int i = 0; i < n; i++) {
        int h = inputBoxes[i][0];
        int w = inputBoxes[i][1];
        int d = inputBoxes[i][2];

        // Rotation 1: h on top, base = w x d
        boxes[idx].height = h;
        boxes[idx].width  = min(w, d);
        boxes[idx].depth  = max(w, d);
        idx++;

        // Rotation 2: w on top, base = h x d
        boxes[idx].height = w;
        boxes[idx].width  = min(h, d);
        boxes[idx].depth  = max(h, d);
        idx++;

        // Rotation 3: d on top, base = h x w
        boxes[idx].height = d;
        boxes[idx].width  = min(h, w);
        boxes[idx].depth  = max(h, w);
        idx++;
    }

    // Step 2: Sort boxes by their base area (largest base first)
    sortByBaseArea(boxes, totalBoxes);

    // Step 3: Apply DP similar to LIS
    // dp[i] = Maximum stack height with boxes[i] at the TOP of the stack
    int dp[totalBoxes];
    for (int i = 0; i < totalBoxes; i++) {
        dp[i] = boxes[i].height;  // At minimum, use just this box
    }

    // For each box, find all boxes that can go below it
    for (int i = 1; i < totalBoxes; i++) {
        for (int j = 0; j < i; j++) {
            if (canPlace(boxes[i], boxes[j])) {
                if (dp[j] + boxes[i].height > dp[i]) {
                    dp[i] = dp[j] + boxes[i].height;
                }
            }
        }
    }

    // Step 4: Find the maximum height
    int maxHeight = 0;
    for (int i = 0; i < totalBoxes; i++) {
        if (dp[i] > maxHeight) {
            maxHeight = dp[i];
        }
    }

    cout << "\nMaximum Stack Height: " << maxHeight << endl;
}

int main() {
    int n;

    cout << "=== Box Stacking Problem (Dynamic Programming) ===" << endl;
    cout << "Enter the number of boxes: ";
    cin >> n;

    int boxes[n][3];

    cout << "\nEnter height, width, and depth for each box:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Box " << i + 1 << " (height width depth): ";
        cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];
    }

    // Solve Box Stacking
    boxStacking(boxes, n);

    return 0;
}

/*
============================
Time Complexity:
  O(n^2) -> DP loop with rotations considered (3n total boxes)

Space Complexity: O(n) -> For dp array and rotated boxes array

Key Concept: Each box has 3 rotations. After sorting by base area,
             problem reduces to Longest Increasing Subsequence (LIS).
============================
*/
