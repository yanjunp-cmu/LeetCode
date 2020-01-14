/*
 * Approach: expand from center
 * for a string with size N, the total center position is 2N-1
 * expand a center as long as it can
 */
class Solution {
public:
    int countSubstrings(string s) {
        int result = 0, N = s.size();
        for (int center = 0; center <= 2 * N - 1; center++){
            int left = center/2;
            int right = left + center % 2;
            while (left >= 0 && right < N && s[left] == s[right]){
                result++;
                left--;
                right++;
            }
        }
        return result;
    }
};

/*
 * Approach: Brute Force
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() -1;
        while (left <= right){
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++){
            for (int j = i; j < s.size(); j++){
                // cout << s.substr(i, j-i) << endl;
                if (isPalindrome(s.substr(i, j-i+1)))
                    result++;
            }
        }        
        return result;
    }
};