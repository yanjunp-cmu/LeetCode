/*
 * Approach: dp
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        
        vector<vector<long>> dp(m, vector<long>(n, 0));
        // initialization        
        if (obstacleGrid[0][0] == 0)
            dp[0][0] = 1;
        
        // transition function
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (!obstacleGrid[i][j]){
                    if(i-1 >= 0) 
                        dp[i][j] += dp[i-1][j];
                    if(j-1 >= 0) 
                        dp[i][j] += dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};