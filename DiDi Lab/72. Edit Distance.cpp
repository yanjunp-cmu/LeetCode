/*
 * dynamic programming approach
 * dp table is (i+1) x (j+1)
 * dp[i][j] represents the number of operation needed to convert word1[0 ... i-1] to word2[0 ... j-1]
 * if word1[i-1] == word2[j-1]
        dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1] - 1)
   else
        dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])

 * dp[i-1][j]   delete
 * dp[i][j-1]   insert
 * dp[i-1][j-1] replace
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp initialization
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        for (int i = 0; i < word1.size() + 1; i++)
            dp[i][0] = i;
        for (int j = 0; j < word2.size() + 1; j++)
            dp[0][j] = j;
        for (int i = 1; i < word1.size() + 1; i++){
            for (int j = 1; j < word2.size() + 1; j++){
                
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1] - 1));
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};