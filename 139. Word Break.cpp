/*
 * Brute Force: recursion + backtracking
 * time complexity:     O(2^n)
 * space complexity:    O(n)
 */

class Solution {
private:
    bool rec(string s, set<string> dict) {
        if (dict.find(s) != dict.end()) return true;
        for (int i = 0; i < s.size(); i++){
            if (dict.find(s.substr(0,i + 1)) != dict.end() 
                && rec(s.substr(i + 1, s.size() - (i + 1)), dict)){
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // build a hashset
        set<string> dict;
        for (string s : wordDict){
            dict.insert(s);
        }
        // use recursion to check validity
        return rec(s, dict);
    }
};


/*
 * Dynamic Programming
 * construct a vector of bool of size of s.size() + 1
 *      dp[i] is set to true if a valid word (word sequence) ends there
 *      dp[j] indicates a valid word ending on j
 *      do dictionary look up in case the preceding position j with dp[j] == true is found
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // build a hashset
        set<string> dict;
        for (string s : wordDict){
            dict.insert(s);
        }
        if (dict.size() == 0) return false;
        // dynamic programming
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    // substring from j to i
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        return dp[s.size()];
    }
};