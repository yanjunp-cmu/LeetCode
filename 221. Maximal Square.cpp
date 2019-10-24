/*
 * 2D dynamic programming
 * dp matrix is (nR+1) x (nC+1)
 * dp[i][j] represents the longest sqr_len cornered at (i-1,j-1)
 * the new corner is the right corner of the square with length min(left, up, left_up) + 1
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int nR = matrix.size(), nC = matrix[0].size();
        vector<vector<int>> dp(nR + 1, vector<int>(nC + 1, 0));
        int maxsqlen = 0;
        for (int i = 1; i <= nR; i++){
            for (int j = 1; j <= nC; j++){
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = min( min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    maxsqlen = max(maxsqlen, dp[i][j]);
                }
            }
        }        
        return maxsqlen * maxsqlen;
    }
};

/*
 * 1D dynamic programming
 * dp array is nC+1 long
 * use a prev to keep track of dp[i-1][j-1] as if in 2D DP solution
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int nR = matrix.size(), nC = matrix[0].size();
        vector<int> dp(nC + 1, 0);
        int prev = 0;
        int maxsqlen = 0;
        
        for (int i = 1; i <= nR; i++){
            for (int j = 1; j <= nC; j++){
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] =min(min(dp[j - 1], prev), dp[j]) + 1;
                    maxsqlen = max(maxsqlen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }        
        return maxsqlen * maxsqlen;
    }
};