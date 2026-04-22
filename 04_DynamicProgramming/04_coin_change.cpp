// Program: Coin Change Problem (Minimum Coins) - Dynamic Programming
// What it does: Given coin denominations and a target amount, find the
//               MINIMUM number of coins needed to make that amount.
//               (You have unlimited supply of each coin denomination)
//
// Example Input:
//   Coins: 1, 5, 6, 9
//   Amount: 11
// Expected Output: Minimum coins = 2 (coins 5 + 6)

#include <iostream>
using namespace std;

// Function to solve Coin Change using DP
void coinChange(int coins[], int numCoins, int amount) {
    // dp[a] = Minimum coins needed to make amount 'a'
    int dp[amount + 1];

    // Initialize all amounts with a large number (represents impossible/infinity)
    for (int a = 0; a <= amount; a++) {
        dp[a] = amount + 1;  // Larger than any valid answer
    }

    // Base case: 0 coins needed to make amount 0
    dp[0] = 0;

    // Step: For each amount from 1 to target amount
    for (int a = 1; a <= amount; a++) {

        // Try all coin denominations
        for (int c = 0; c < numCoins; c++) {

            // Only use this coin if it doesn't exceed current amount
            if (coins[c] <= a) {
                // Option: Use coin[c] for current amount
                // Remaining amount = a - coins[c], which needs dp[a - coins[c]] coins
                int coinsUsed = dp[a - coins[c]] + 1;

                // Update dp[a] if using this coin gives fewer coins
                if (coinsUsed < dp[a]) {
                    dp[a] = coinsUsed;
                }
            }
        }
    }

    // Check if the amount can be made
    if (dp[amount] > amount) {
        cout << "\nAmount " << amount << " CANNOT be made with given coins." << endl;
    } else {
        cout << "\nMinimum coins needed to make " << amount << ": " << dp[amount] << endl;

        // Trace back to find which coins were used
        cout << "Coins used: ";
        int remaining = amount;
        while (remaining > 0) {
            // Find which coin was used at this amount
            for (int c = 0; c < numCoins; c++) {
                if (coins[c] <= remaining && dp[remaining - coins[c]] == dp[remaining] - 1) {
                    cout << coins[c] << " ";
                    remaining -= coins[c];
                    break;  // Move to next step
                }
            }
        }
        cout << endl;
    }
}

int main() {
    int numCoins, amount;

    cout << "=== Coin Change Problem (Dynamic Programming) ===" << endl;
    cout << "Enter the number of coin denominations: ";
    cin >> numCoins;

    int coins[numCoins];

    cout << "Enter the coin denominations: ";
    for (int i = 0; i < numCoins; i++) {
        cin >> coins[i];
    }

    cout << "Enter the target amount: ";
    cin >> amount;

    // Solve Coin Change
    coinChange(coins, numCoins, amount);

    return 0;
}

/*
============================
Time Complexity:
  O(numCoins * amount) -> For each amount, try all coins

Space Complexity: O(amount) -> For the 1D dp array
============================
*/
