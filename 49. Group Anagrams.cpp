class Solution {
public:
	vector<vector<string>> groupAnagrams(const vector<string>& strs) {
		vector<vector<string>> result;
		// use an unordered_map for hashing
		// hash key is sorted string ("code" ->"cdeo")
		// has value is a vector of strings
		unordered_map<string, vector<string>> hashmap;
		for(const auto& i : strs){
			string s = i;
			sort(s.begin(), s.end());
			hashmap[s].push_back(i);
		}
		// push hash values into result
		for(const auto& i : hashmap){
			vector<string> s = i.second;
			result.push_back(s);
		}
		return result;	
	}
};