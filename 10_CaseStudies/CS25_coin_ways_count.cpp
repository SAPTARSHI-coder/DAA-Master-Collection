// ============================================================
// CASE STUDY 25: Coin Change - Count Total Ways (DP)
// ============================================================
//
// PROBLEM STATEMENT:
//   Given coin denominations and a target amount, count the TOTAL
//   NUMBER OF WAYS to make the amount using unlimited coins.
//   (This is DIFFERENT from the minimum coins problem — here we COUNT ways.)
//
// REAL-LIFE: Currency exchange ways, ways to give change, number of
//            ways to pay a bill using available denominations.
//
// ============================================================
// PATTERN RECOGNITION: WHY DP (Unbounded)?
// ============================================================
//
//  KEY OBSERVATION: "Count WAYS" + "items reusable" = DP counting
//    ways[amount] = sum of ways[amount - coin] for each coin
//
//  CRITICAL DIFFERENCE FROM CS coin change (min coins):
//    Min coins:    dp[i] = min(dp[i], 1 + dp[i - coin])   -> MINIMIZE
//    Count ways:   dp[i] += dp[i - coin]                  -> COUNT/SUM
//
//  OUTER LOOP must iterate COINS first, then AMOUNTS.
//  (If amounts first, we count ordered sequences, not combinations)
//
// ============================================================

#include <iostream>
using namespace std;

void countCoinWays(int coins[], int numCoins, int amount) {
    // dp[i] = number of ways to make amount i
    long long dp[amount + 1];
    for (int i = 0; i <= amount; i++) dp[i] = 0;

    dp[0] = 1;  // 1 way to make 0: use no coins

    // IMPORTANT: Iterate coin FIRST to avoid counting ordered sequences
    // (We want {1,2} and {2,1} to count as ONE combination, not two)
    for (int c = 0; c < numCoins; c++) {
        for (int i = coins[c]; i <= amount; i++) {
            dp[i] += dp[i - coins[c]];
        }

        cout << "After adding coin " << coins[c] << ": ways[] = ";
        for (int i = 0; i <= amount; i++) cout << dp[i] << " ";
        cout << endl;
    }

    cout << "\nTotal number of ways to make " << amount
         << " using given coins: " << dp[amount] << endl;
}

int main() {
    int numCoins, amount;
    cout << "=== CASE STUDY 25: Count Coin Ways (DP - Unbounded) ===" << endl;
    cout << "Enter number of coin types: ";
    cin >> numCoins;

    int coins[numCoins];
    cout << "Enter coin denominations: ";
    for (int i = 0; i < numCoins; i++) cin >> coins[i];

    cout << "Enter target amount: ";
    cin >> amount;

    cout << "\nDP Trace (ways[i] = ways to form amount i):" << endl;
    countCoinWays(coins, numCoins, amount);

    return 0;
}

/*
============================
Time:  O(numCoins * amount)
Space: O(amount)

KEY DISTINCTION (memorize for viva!):
  Coin Change (MIN coins):   dp[i] = min(dp[i], 1 + dp[i-coin]) — iterate amount first OK
  Coin Change (COUNT ways):  dp[i] += dp[i-coin] — iterate COIN first to avoid duplicates
  Coin Change (COUNT sequences): dp[i] += dp[i-coin] — iterate AMOUNT first
============================
*/
