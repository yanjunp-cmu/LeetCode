/*
 * Approach: BFS
 */
class Solution {
private:
    int BFS(vector<vector<int>>& matrix, queue<pair<int,int>>& BFS_que){
        int dist = 0;
        bool isDone = false;
         // directions: left, right, up, down 
        int dirX[4] = {-1, 1, 0,  0};
        int dirY[4] = { 0, 0, 1, -1};
        // BFS here
        while (!BFS_que.empty()){
            int size = BFS_que.size();
            for (int i = 0; i < size; i++){
                auto tmp = BFS_que.front();
                BFS_que.pop();
                int row = tmp.first;
                int col = tmp.second;
                if (matrix[row][col] == 0)
                    return dist;
                for (int j = 0; j < 4; j++){
                    if(row + dirX[j] >= 0 && row + dirX[j] < matrix.size() && 
                       col + dirY[j] >= 0 && col + dirY[j] < matrix[0].size()){
                        BFS_que.push(make_pair(row+dirX[j], col+dirY[j]));
                    }
                }
            }
            dist++;
        }
        return -1;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        
        vector<vector<int>> res(vector<vector<int>>(rows, vector<int>(cols, 0)));
        
        for(int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                // skip 0s in the matrix
                if (matrix[i][j] == 0)
                    continue;
                // BFS here
                queue<pair<int,int>> BFS_que;
                BFS_que.push(make_pair(i,j));
                res[i][j] = BFS(matrix, BFS_que);
            }
        }
        return res;
    }
};


/*
 * Approach: Two pass dp
 */
class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0)
                    dist[i][j] = 0;
                else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }

        return dist;
    }
};