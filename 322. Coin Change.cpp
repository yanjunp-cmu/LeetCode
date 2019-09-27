/*
 * Bottom-up dynamic programming
 *      dp vector size is amoung + 1 (including 0)
 *          initialize dp vector values to amount+1 except for dp[0] = 0
 *          for dp[] starting from 1
 *              if coin value <= dp[i]
 *                  dp[i] = min(dp[i], dp[i - coins[j]] + 1)
 *                  *** plus one because: dp[i - coins[j]] times plus the one extra coin[j] currently using
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        // dp solution
        for (int i = 1; i <= amount; i++){
            for (int j = 0; j < coins.size(); j++){
                if (coins[j] <= i){
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if (dp[amount] > amount)
            return -1;
        else 
            return dp[amount];
    }
};