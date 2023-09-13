// Time Limit Exceeds

using namespace std;

#include <vector>
#include <climits>

class Solution {
public:
    int coinChangeRec(vector<int>& coins, int amount) {
        // Base case: If the amount is zero, no coins are needed
        if (amount == 0)
            return 0;

        // Initialize the minimum number of coins needed as a large value
        int minCoins = INT_MAX;

        // Try each coin denomination
        for (int coin : coins) 
        {
            // Skip coins that are larger than the current amount
            if(coin > amount)
                continue;

            // Recursively calculate the number of coins needed for the remaining amount
            int remainingCoins = coinChangeRec(coins, amount - coin);

            // If the remainingCoins is a valid answer and smaller than the current minCoins,
            // update minCoins with remainingCoins + 1 (to include the current coin)
            if (remainingCoins != -1)
                minCoins = min(minCoins, remainingCoins + 1);
        }

        // If minCoins remains INT_MAX, it means no valid combination was found, so return -1
        return (minCoins == INT_MAX) ? -1 : minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        return coinChangeRec(coins, amount);
    }
};