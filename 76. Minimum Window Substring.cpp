class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        if (s.size() < t.size() || s.size() == 0 || t.size() == 0) return res;
        
        // use a vector to store existence of characters in t
        vector<int> dict(128, 0);
        for (char c:t) dict[c]++;
        
        // judge vector is used to record existence of s
        vector<int> judge(128,0);
        int reslen = INT_MAX;
        
        // sliding window
        int left = 0, right = 0, count = 0;
        while(right < s.size()){
            bool is_done = false;
            // move the right marker to the left so that from left to right, substr contains all characters in t
            while (right < s.size() && count != t.size()){
                if (dict[s[right]] > 0){
                    judge[s[right]]++;
                    if(judge[s[right]] <= dict[s[right]]) count++;
                }
                right++;
            }
            if (count == t.size()) is_done = true;
            
            // move left marker to the right until the substr no longer contains all characters in t
            while (left< right && count == t.size()){
                if (dict[s[left]] > 0){
                    judge[s[left]]--;
                    if(judge[s[left]] < dict[s[left]]) count--;
                }
                left++;
            }
            
            // choose to accept the substr or not
            if (is_done && right - left + 1 < reslen){
                reslen = right - left + 1;
                res = s.substr(left - 1, right - left + 1);
            }
        }
        return res;
    }
};