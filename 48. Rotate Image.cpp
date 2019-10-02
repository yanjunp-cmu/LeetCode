class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int nR = matrix.size(), nC = matrix[0].size();
        // flip upside down
        for (int i = 0; i < nR/2; i++){
            for (int j = 0; j < nC; j++){
                swap(matrix[i][j], matrix[nR - 1 -i][j]);
            }
        }    
        
        // flip along the diagonal line
        for (int i = 0; i < nR; i++){
            for (int j = i; j < nC; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};