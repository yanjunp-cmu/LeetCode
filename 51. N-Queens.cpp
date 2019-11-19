/*
 * backtracking 
 */
class Solution {
private:
    bool isValid(vector<int>& new_placement, vector<vector<int>>& placement){
        if (placement.empty())
            return true;
        for (int i = 0; i < placement.size(); i++){
            // check if same column
            if (new_placement[1] == placement[i][1])
                return false;
            // check if same row
            if (new_placement[0] == placement[i][0])
                return false;
            // check if on the diagonal line
            if (abs(new_placement[0] - placement[i][0]) 
                == abs(new_placement[1] - placement[i][1]))
                return false;
        }
        return true;
    }
    void dfs(vector<vector<string>>& result, vector<vector<int>>& placement, int num, int n){
        if (num >= n){
            // build the result and return
            vector<string> config(n, string(n, '.'));
            for (int i = 0; i < placement.size(); i++){
                int row = placement[i][0];
                int col = placement[i][1];
                config[row][col] = 'Q';
            }
            result.push_back(config);
            return;
        }
        for (int i = 0; i < n; i++){
            vector<int> new_placement = {i, num};
            if (isValid(new_placement, placement)){
                placement.push_back(new_placement);
                dfs(result, placement, num+1, n);
                placement.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<int>> placement;
        dfs(result, placement, 0, n);
        return result;
    }
};