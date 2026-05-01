// Program: Stock Buy and Sell to Maximize Profit (Greedy)
// What it does: Given stock prices for N days, find the MAXIMUM profit
//               by buying and selling stocks. You can make MULTIPLE TRANSACTIONS
//               (buy and sell multiple times), but you must sell before buying again.
//
// Approach: Simple Greedy - Add profit for every consecutive increasing pair.
//            (Buy at every valley, sell at every peak)
//
// Example Input: 7  1  5  3  6  4
// Expected Output: Max Profit = 7 (Buy at 1, Sell at 5 -> +4; Buy at 3, Sell at 6 -> +3)

#include <iostream>
using namespace std;

// Function to calculate maximum profit from stock prices
void stockBuySell(int prices[], int n) {
    if (n == 1) {
        cout << "Only 1 day, no profit possible." << endl;
        return;
    }

    int totalProfit = 0;

    cout << "\nProfitable transactions:" << endl;
    cout << "-----------------------------" << endl;

    // Greedy: Capture profit whenever price goes UP
    // This is equivalent to buying at every valley and selling at every peak
    for (int i = 1; i < n; i++) {
        // If today's price is higher than yesterday's, we gain profit
        if (prices[i] > prices[i - 1]) {
            int profit = prices[i] - prices[i - 1];
            totalProfit += profit;
            cout << "Buy at Day " << i << " (Price: " << prices[i - 1]
                 << "), Sell at Day " << i + 1 << " (Price: " << prices[i]
                 << ") -> Profit: " << profit << endl;
        }
    }

    if (totalProfit == 0) {
        cout << "Prices are non-increasing. No profit possible!" << endl;
    } else {
        cout << "\nMaximum Total Profit: " << totalProfit << endl;
    }
}

int main() {
    int n;

    cout << "=== Stock Buy and Sell - Maximize Profit (Greedy) ===" << endl;
    cout << "Enter the number of days: ";
    cin >> n;

    int prices[n];

    cout << "Enter the stock price for each day: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Find maximum profit
    stockBuySell(prices, n);

    return 0;
}

/*
============================
Time Complexity:
  O(n) -> Single pass through the array

Space Complexity: O(1) -> No extra memory

Greedy Key: Instead of tracking exact buy/sell days, add profit for every
            upward movement. This is equivalent to multiple buy-sell cycles.
============================
*/
