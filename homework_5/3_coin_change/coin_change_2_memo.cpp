using namespace std;

#include <vector>


class Solution {
public:

    int changeRecursion(int amount, vector<int>& coins, int index, vector<vector<int>>& memo) {
        // Base case: If the amount is zero, there's one combination (no coins used)
        if (amount == 0)
            return 1;
        

        // If the index goes out of bounds or the remaining amount is negative, return 0
        if (index >= coins.size() || amount < 0)
            return 0;
        

         // If the result is already computed, return it from the memoization table
        if (memo[index][amount] != -1)
            return memo[index][amount];

        // Calculate the number of combinations by either using the current coin or not using it
        int combinationsWithCoin = changeRecursion(amount - coins[index], coins, index, memo);
        int combinationsWithoutCoin = changeRecursion(amount, coins, index + 1, memo);

        // Store the result in the memoization table and return it
        memo[index][amount] = combinationsWithCoin + combinationsWithoutCoin;
        return memo[index][amount];
    }

    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return changeRecursion(amount, coins, 0, memo);
    }
};