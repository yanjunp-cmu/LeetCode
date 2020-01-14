/*
 * Approach: sliding window
 * use a hash set to keep track of seen characters
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int maxlen = 0, i = 0, j = 0;
        unordered_set<char> char_map;
        while (i < s.size() && j < s.size()){
            if (char_map.find(s[j]) == char_map.end()){
                char_map.insert(s[j]);
                j++;
                maxlen = max(maxlen, j - i);
            } else {
                char_map.erase(char_map.find(s[i]));
                i++;
            }
        }
        return maxlen;
    }
};