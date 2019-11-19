/*
 * Method: BFS
 * when a location has no nearby mines, push all its neighbors into the queue
 * if a location has nearby mines, just update the number
 */
class Solution {
public:
    int mineCheck(vector<vector<char>>& board, vector<int>& pos, int row, int col){
        int m = pos[0], n = pos[1];
        int result = 0;
        for (int i = m-1; i <= m+1; i++){
            for (int j = n-1; j<= n+1; j++){
                if (i < 0 || i >= row)
                    continue;
                if (j < 0 || j >= col)
                    continue;
                if (board[i][j] == 'M')
                    result += 1;
            }
        }
        return result;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = board.size();
        int col = board[0].size();
        // clicked on the mine
        if (board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        // copy the board onto the result
        vector<vector<char>> result = board;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                result[i][j] = board[i][j];
            }
        }
        // BFS, create a visited set
        queue<vector<int>> que;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        que.push(click);
        while(!que.empty()){
            auto tmp = que.front();
            que.pop();
            int r = tmp[0], c = tmp[1];
            if (visited[r][c] == 0){
                visited[r][c] = 1;
                int mine_num = mineCheck(board, tmp, row, col);
                if (mine_num == 0){
                    result[r][c] = 'B';
                    if (r - 1 >= 0){         // up
                        que.push({r-1,c});
                        if (c - 1 >= 0)      // left-up
                            que.push({r-1,c-1});
                        if (c + 1 < col)     // right-up
                            que.push({r-1,c+1});
                    }
                    if (r + 1 < row){        // down
                        que.push({r+1,c});
                        if (c - 1 >= 0)      // left-down
                            que.push({r+1,c-1});
                        if (c + 1 < col)     // right-down
                            que.push({r+1,c+1});
                    }
                    if (c - 1 >= 0)         // left
                        que.push({r, c-1});
                    if (c + 1 < col)        // right
                        que.push({r, c+1});
                } else {
                    result[r][c] = mine_num + '0';
                }   
            }
        }
        return result;
    }
};