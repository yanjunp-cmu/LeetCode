/*
 * Dynamic Programming
 *      dp[i] represents longest valid parentheses ending at i-th char
 *      Therefore, '(' can never have a non-zero entry
 *      corner cases: when i < 2
 *
 * Corner Case:
 *      ( ) ( ( ) )
 *      0 2 0 0 2 x
 *      need to accumulate the first pair into the sum!!!!
 *      Therefore, we need to add dp[i - dp[i-1] - 2]!!!
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        vector<int> dp(s.size(), 0);
        for(int i = 1; i < s.size(); i++){
            if (s[i] == ')'){
                if (s[i-1] == '('){
                    if (i >= 2){
                        dp[i] = dp[i-2] + 2;
                    } else {
                        dp[i] = 2;
                    }
                } else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] =='(') {
                    // corner case
                    if (i - dp[i-1] >= 2){
                        dp[i] = dp[i-1] + dp[i - dp[i-1] - 2] + 2;
                    } else {
                        dp[i] = dp[i-1] + 2;
                    }
                    
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};