/*
 * improved brute force with dynamic programming
 * idea is that compute maximum width at each index (i,j)
 * then compute upwards so that the maximum area of the rectangle having the lower corner at (i,j) is calculated
 * width = min(width, dp[k][j])
 * maxarea = max(maxarea, width*(i-k+1))
**/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxarea = 0;
        // initialize a dp matrix
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size() ,0));
        for (int i = 0; i < dp.size(); i++){
            for (int j = 0; j < dp[0].size(); j++){
                if (matrix[i][j] == '1'){
                    if (j == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i][j-1] + 1;
                    
                    int width = dp[i][j];
                    
                    // compute the maximum area rectangle with a lower right corner at (i,j)
                    for (int k = i; k >=0; k--){
                        width = min(width, dp[k][j]);
                        maxarea = max(maxarea, width*(i - k + 1));
                    }
                }
            }
        }
        return maxarea;
    }
};