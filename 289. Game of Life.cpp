/**********************************************/  
/*                  METHOD 1                  */
/*                 COPY BOARD                 */  
/**********************************************/    
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        
        // make a copy of the original board
        vector<vector<int> >cpy_board(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                cpy_board[i][j] = board[i][j];
            }
        }
        
        
        // start to apply rules
        for(int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                
                int count = 0;
                // check its neighbor count
                for (int row_nei = i - 1; row_nei <= i + 1; row_nei++){
                    for (int col_nei = j - 1; col_nei <= j + 1; col_nei++){
                        if (row_nei >= 0 && col_nei >= 0 && row_nei < row && col_nei < col){
                            count += cpy_board[row_nei][col_nei];
                        }
                    }
                }
                count -= cpy_board[i][j];
                
                // live cell
                if (board[i][j] == 1){
                    // rule 1
                    if (count < 2) board[i][j] = 0;
                    
                    // rule 2
                    if (count == 2 || count == 3) board[i][j] = 1;
                    
                    // rule 3
                    if (count > 3) board[i][j] = 0;
                    
                } else if (board[i][j] == 0){ // dead cell
                    // rule 4
                    if (count == 3) board[i][j] = 1;
                }
            }
        }
    }
};

/**********************************************/  
/*                  METHOD 2                  */
/*                BIT WISE OP                 */  
/**********************************************/ 
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int count = 0;
                for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                    for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                        count += board[I][J] & 1;
                if (count == 3 || count - board[i][j] == 3)
                    board[i][j] |= 2;
            }
        }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                board[i][j] >>= 1;
    }
};