class Solution {
private: 
    int steps, nR, nC;
    int result;
    int dirX[4] = {-1, 1,  0, 0};
    int dirY[4] = { 0, 0, -1, 1};
    
    void backtrack(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int K){
        // i,j are grid coordinate
        if (grid[i][j] == 2 && K == steps){
            result++;
            return;
        }
        if (grid[i][j] == 2 && K != steps)
            return;
        
        visited[i][j] = 1;
        for (int l = 0; l < 4; l++){
            int nexti = i + dirY[l];
            int nextj = j + dirX[l];
            
            if (nexti >= 0 && nexti < nR && nextj >=0 && nextj < nC 
                && !visited[nexti][nextj] && grid[nexti][nextj] != -1)
                backtrack(grid, visited, nexti, nextj, K+1);
        }
        visited[i][j] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        nR = grid.size();
        if (!nR)
            return 0;
        nC = grid[0].size();
        
        result = 0;
        // scan the grid to obtain the required step size
        int zero_cnt = 0;
        int starti, startj;
        for (int i = 0; i < nR; i++){
            for (int j = 0; j < nC; j++){
                if (grid[i][j] == 0)
                    zero_cnt++;
                if (grid[i][j] == 1){
                    starti = i;
                    startj = j;
                }
            }
        }
        steps = zero_cnt + 1;
        // perform backtracking
        vector<vector<int>> visited(nR, vector<int>(nC, 0));
        backtrack(grid, visited, starti, startj, 0);
        return result;
    }
};