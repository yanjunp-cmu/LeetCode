/*
 * BFS like num of islands
 * keep track of area during iteration
 * one thing to note is that a visited set is maintained to prevent double counting
 */
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        if (!row)
            return 0;
        int col = grid[0].size();
        int max_area = 0;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                int area;
                if (grid[i][j] == 1){
                    area = 0;
                    queue<vector<int>> que;
                    que.push({i,j});
                    while (!que.empty()){
                        vector<int> tmp = que.front();
                        que.pop();
                        int r = tmp[0], c = tmp[1];
                        if (visited[r][c] == 0){
                            area += 1;
                            grid[r][c] = 0;
                            visited[r][c] = 1;
                            if (r - 1 >= 0 && grid[r-1][c] == 1)
                                que.push({r-1,c});
                            if (r + 1 < row && grid[r+1][c] == 1)
                                que.push({r+1,c});
                            if (c - 1 >= 0 && grid[r][c-1] == 1)
                                que.push({r,c-1});
                            if (c + 1 < col && grid[r][c+1] == 1)
                                que.push({r,c+1});   
                            }
                    }
                }
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};