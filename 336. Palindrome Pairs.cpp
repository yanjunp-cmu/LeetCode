/*
Main logic part. 
    Partition the word into left and right, and see 
    1) if there exists a candidate in map equals the left side of current word, and right side of current word is palindrome, so concatenate(current word, candidate) forms a pair: left | right | candidate. 
    2) same for checking the right side of current word: candidate | left | right.
*/



class Solution {
private:
    bool isPal(string& s, int l, int r){
        while(l<r && s[l]==s[r]) l++, r--;
        return l >= r;
    }
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > vv;
        if(words.empty()) return vv;

        // create a hashmap
        // hash key is the word itself
        unordered_map<string, int> word_map;
        for(int i = 0; i < words.size(); ++i) word_map[words[i]] = i;

        // traverse through the vector
        for(int i = 0; i < words.size(); ++i){
            // len is the current word length
            // t is the index in the hashmap
            int len = words[i].length(), t;
            // cur is the current word
            // t_str is the desired palindrom of the current word 
            string cur = words[i], t_str;
            // reverse the current word
            reverse(cur.begin(), cur.end());

            for(int l = 0; l <= len; ++l){
                if(isPal(cur, 0, l-1)){
                    t_str = cur.substr(l);
                    if(word_map.count(t_str)){
                        t = word_map[t_str];
                        if(t!=i) vv.push_back(vector<int>{i, t});
                    }
                }
                if(isPal(cur, l, len-1)){
                    t_str = cur.substr(0, l);
                    if(word_map.count(t_str)){
                        t = word_map[t_str];
                        if(len>l) vv.push_back(vector<int>{t, i});
                    }
                }
            }
        }
        return vv;
    }
};