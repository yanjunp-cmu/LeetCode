/*
 * Approach: backtracking
 */
class Solution {
private:
    void backtrack(vector<int> nums, vector<vector<int>>& res, vector<int>& tmp, int begin){
        res.push_back(tmp);
        for (int i = begin; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            backtrack(nums, res, tmp, i+1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
		vector<int> vec;
		backtrack(nums, res, vec, 0);
		return res;
    }
};