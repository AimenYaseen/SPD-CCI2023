// Time limit exceeds

using namespace std;

#include <vector>


class Solution {
public:

    int changeRecursion(int amount, vector<int>& coins, int index) {
        // Base case: If the amount is zero, there's one combination (no coins used)
        if (amount == 0) {
            return 1;
        }

        // If the index goes out of bounds or the remaining amount is negative, return 0
        if (index >= coins.size() || amount < 0) {
            return 0;
        }

        // Calculate the number of combinations by either using the current coin or not using it
        int combinationsWithCoin = changeRecursion(amount - coins[index], coins, index);
        int combinationsWithoutCoin = changeRecursion(amount, coins, index + 1);

        // Return the sum of combinations using and not using the current coin
        return combinationsWithCoin + combinationsWithoutCoin;
    }
    
    int change(int amount, vector<int>& coins) {
        return changeRecursion(amount, coins, 0);
    }
};