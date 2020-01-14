/*
 * Approach I: reduce the search space
 * Starting from the bottom left corner:
 *      If the number is larger than the target, reduce a row
 *      If the number is smaller than the target, increase a column
 * exit upon found or out of bound
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        
        int row = matrix.size();
        int col = matrix[0].size();
        int ptr_row = row - 1;
        int ptr_col = 0;
        
        bool is_present = false;
        while (ptr_row >= 0 && ptr_row < row && ptr_col >= 0 && ptr_col < col && !is_present){
            if (matrix[ptr_row][ptr_col] < target){
                ptr_col ++;
            } else if (matrix[ptr_row][ptr_col] > target){
                ptr_row --;
            } else {
                is_present = true;
            }
        }
        return is_present;
    }
};