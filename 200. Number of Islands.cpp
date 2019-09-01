/*
    DFS
*/
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int nR = grid.size(), nC = grid[0].size();
        // indicate visited by turning '1' to '0'
        grid[i][j] = '0';
        // check up
        if (i - 1 >= 0 && grid[i-1][j] == '1') dfs(grid, i - 1, j);
        // check down
        if (i + 1 < nR && grid[i+1][j] == '1') dfs(grid, i + 1, j);
        // check left    
        if (j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        // check right
        if (j + 1 < nC && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.empty()) return res;
        int nR = grid.size(), nC = grid[0].size();
        for (int i = 0; i < nR; i++){
            for (int j = 0; j < nC; j++){
                // if grid[i][j] is '1', there is at least one island
                if (grid[i][j] == '1'){                    
                    res++;
                    dfs(grid, i, j);
                }
                
            }
        }
        return res;
    }
};

/*
    BFS
    requires a queue to store qualified node
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.empty()) return res;
        
        queue<pair<int,int>> bfs_q;
        
        int nR = grid.size(), nC = grid[0].size();
        
        for (int i = 0; i < nR; i++){
            for (int j = 0; j < nC; j++){
                if (grid[i][j] == '1'){                    
                    res++;
                    bfs_q.push({i,j});
                    while(!bfs_q.empty()){
                        auto root = bfs_q.front();
                        bfs_q.pop();
                        int row = root.first, col = root.second;
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            bfs_q.push({row-1, col}); 
                            grid[row-1][col] = '0';
                        }
                        if (row + 1 < nR && grid[row+1][col] == '1') {
                            bfs_q.push({row+1, col}); 
                            grid[row+1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            bfs_q.push({row, col-1}); 
                            grid[row][col-1] = '0';
                        }
                        if (col + 1 < nC && grid[row][col+1] == '1') {
                            bfs_q.push({row, col+1}); 
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return res;
    }
};