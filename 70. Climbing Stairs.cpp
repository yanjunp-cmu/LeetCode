/*
 * Use dynamic programming
 * observation:
 * step 1: 1
 * step 2: 1 + 1 = 2
 * step 3: (1,1,1), (1,2), (2,1)
 * thus a Fibonacci Pattern shows
**/

class Solution {
public:
    int climbStairs(int n) {
        if (!n) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};