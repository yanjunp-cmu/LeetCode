/*
 * Approach: expand from the middle
 * starting from the beginning for both pointers
 * skip all same characters and set right to the right-most same character
 * expand left to the left and right to the right
 * us i to keep track of where last time stopped
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 0;
        int i = 0;
        string longestP = "";
        while (i < s.size()){
            int left = i, right = i;
            // jump the same character
            while (i < s.size() && s[i] == s[right])
                i++;
            right = i - 1;
            // expand left and right pointers
            while (left >= 0 && right <= s.size() - 1 && s[left] == s[right]){
                left--;
                right++;
            }
            if (maxlen < (right - left - 1)) {
                maxlen = right - left - 1;
                longestP = s.substr(left + 1, maxlen);
            }
        }
        return longestP;
    }
};