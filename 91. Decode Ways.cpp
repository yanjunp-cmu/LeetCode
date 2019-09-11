/*
 * DFS Solution
 * when the next two digits is from 1 to 26, search i+2
 * then search i+1
 * TIME OUT
**/

class Solution {
public:
    int dfs(string s, int start){
        if (s[start] == '0') return 0;
        if (start == s.size()-1 || start == s.size()) return 1;
        int i = start;
        int res = 0;
        if (i + 1 < s.size() && (s[i] - '0' == 1) || ((s[i] - '0') == 2 && (s[i+1]- '0') <= 6)){
            res += dfs(s, start + 2);
        }
            res += dfs(s, start + 1);
        
        return res;
    }
    
    
    int numDecodings(string s) {
        if (s.empty()) return 0;
        return dfs(s, 0);
    }
};


/*
 * DP Solution
 * add up the previous counts
 * if dp[i-2] == 0 && dp[i-1] != 0, then dp[i] = dp[i - 1]
 * if dp[i-2] != 0 && dp[i-1] == 0, then dp[i] = dp[i - 2]
 * if dp[i-2] == 0 && dp[i-1] == 0, then return 0
 * else dp[i] = dp[i - 1] + dp[i - 2]
**/


class Solution {
public:
    int numDecodings(string s) {
       if (s[0] == '0') return 0;
        
        vector<int>dp(s.size() + 1, 1);
        
        for (int i = 2; i <= s.size(); i++) {
            char c1 = s[i - 2];
            char c2 = s[i - 1];
            // no viable interpretation
            if ((c1 == '0'|| c1 > '2') && c2 == '0') return 0;
            // c1 cannot be interpreted on its own
            else if (c1 == '0' && c2 != '0') dp[i] = dp[i - 1];
            // c2 needs to be interpreted with c1
            else if (c1 != '0' && c2 == '0') dp[i] = dp[i - 2];
            // c1 != 0 && c2 != 0
            else if(c1=='1'||(c1=='2' && c2<'7')) dp[i] = dp[i-1] + dp[i - 2];
            else dp[i] = dp[i - 1];
        }
        return dp[s.size()];
    }
};