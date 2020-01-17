/*
 * Approach: greedy algorithm
 * the leading 1 has more weight than all of other ones combined
 * therefore, first flip rows with leading zero
 * then, flip columns with more zeros than ones
 */
class Solution {
private:
    int bin2dec(vector<vector<int>>& A){
        int sum = 0;
        int N = A[0].size() - 1;
        for (int i = 0; i < A.size(); i++){
            for (int j = 0; j <= N; j++){
                sum += A[i][j] * pow(2, (N-j));
            }
        }
        return sum;
    }
    
    void flip_row(vector<vector<int>>& A, int row){
        for (int j = 0; j < A[0].size(); j++){
            A[row][j] = !A[row][j];
        }
    }
    
    void flip_column(vector<vector<int>>& A, int col){
        for (int i = 0; i < A.size(); i++){
            A[i][col] = !A[i][col];
        }
    }
public:
    int matrixScore(vector<vector<int>>& A) {
        // since the left most column has the highest weight, flip rows with leading zero
        for (int i = 0; i < A.size(); i++){
            if (A[i][0] == 0){
                flip_row(A, i);
            }
        }
        
        // now flip columns which have more zeros than ones
        for (int j = 0; j < A[0].size(); j++){
            int num_of_zero = 0;
            for (int i = 0; i < A.size(); i++){
                if (A[i][j] == 0)
                    num_of_zero++;
            }
            if (num_of_zero > (A.size() - num_of_zero))
                flip_column(A, j);
        }
        return bin2dec(A);
    }
};