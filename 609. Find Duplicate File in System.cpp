/*
 *  string parsing + map
 */
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> path_dict;
        vector<vector<string>> ans;
        // string parsing section
        for (string s : paths){
            vector<string> words;
            // split string by space
            int left = 0;
            for (int right = 0; right < s.size(); right++){
                if (s[right] == ' '){
                    words.push_back(s.substr(left, right - left));
                    left = right + 1;
                }
                if (right == s.size() - 1){
                    words.push_back(s.substr(left, right - left + 1));
                }
            }    
            // the first element of the words is the root
            string root = words[0] + '/';
            // parse string to get content and reconstruct file path
            for (int i = 1; i < words.size(); i++){
                string path = "", content = "";
                int left = 0;
                for (int j = 0; j < words[i].size(); j++){
                    if (words[i][j] == '(') {
                        path = root + words[i].substr(left, j - left);
                        left = j + 1;
                    }
                    if (words[i][j] == ')') {
                        content = words[i].substr(left, j - left);
                    }
                }
                path_dict[content].push_back(path);
            }
        }

        // push map into ans
        // if no more than two, don't push
        for (auto it = path_dict.begin(); it != path_dict.end(); it++){
            vector<string> content = it->second;
            if (content.size() > 1)
                ans.push_back(it->second); 
        }  
        return ans;
    }
};