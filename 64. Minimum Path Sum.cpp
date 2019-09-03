/*
    Dynamic Programming
    starting from the bottom right and move to top left
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int nR = grid.size(), nC = grid[0].size();
        for (int i = nR - 1; i >= 0; i--){
            for (int j = nC - 1; j >=0; j--){
                int cur = grid[i][j];
                if (i + 1 < nR && j + 1 < nC) grid[i][j] = cur + min(grid[i+1][j], grid[i][j+1]);
                else if (i + 1 < nR && j + 1 >= nC) grid[i][j] = cur + grid[i+1][j];
                else if (i + 1 >= nR && j + 1 < nC) grid[i][j] = cur + grid[i][j+1];
                else grid[i][j] = cur;
            }
        }
        return grid[0][0];
    }
};