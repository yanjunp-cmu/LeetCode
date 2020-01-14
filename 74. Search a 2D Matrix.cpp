/*
 * Two binary searches
 * time complexity: O(log(n) + log(m))
 */
class Solution {
public:
    int rowSearch(vector<vector<int>>& matrix, int target){
        int t = 0;
        int b = matrix.size() - 1;
        int ncol = matrix[0].size();
        while (t <= b){
            int m = t + (b - t)/2;
            if (matrix[m][0] <= target && matrix[m][ncol - 1] >= target)
                return m;
            if (matrix[m][0] < target)
                t = m + 1;
            else if (matrix[m][0] > target)
                b = m - 1;
        }
        return -1;
    }
    
    bool colSearch(vector<int>& vector, int target){
        int left = 0, right = vector.size();
        bool found = false;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (vector[mid] < target)
                left = mid + 1;
            else if (vector[mid] > target)
                right = mid - 1;
            else 
                return true;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        if (matrix[0].empty())
            return false; 
        int row = 0;
        if ((row = rowSearch(matrix, target)) == -1)
            return false;
        return colSearch(matrix[row], target);
    }
};