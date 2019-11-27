class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int A_len = A.size(), B_len = B.size();
        int i = 0, j = 0;
        vector<vector<int>> result;
        while(i < A_len && j < B_len){
            vector<int> A_tmp = A[i];
            vector<int> B_tmp = B[j];
            if (B_tmp[0] < A_tmp[0]){   // B starts before A does
                if (B_tmp[1] < A_tmp[0])
                    j++;
                else if (B_tmp[1] == A_tmp[0]){
                    result.push_back({A_tmp[0],B_tmp[1]});
                    j++;
                } else if (A_tmp[0] < B_tmp[1] && B_tmp[1] <= A_tmp[1]){
                    result.push_back({A_tmp[0],B_tmp[1]});
                    j++;
                } else { // A_tmp is included in the B_tmp
                    result.push_back({A_tmp[0],A_tmp[1]});
                    i++;
                }
            } else if (A_tmp[0] <= B_tmp[0] && B_tmp[0] <= A_tmp[1]){    // B starts within A
                if (B_tmp[1] <= A_tmp[1]){   // B_tmp is included in the A_tmp
                    result.push_back({B_tmp[0],B_tmp[1]});
                    j++;
                } else {
                    result.push_back({B_tmp[0],A_tmp[1]});
                    i++;
                }
            } else {    // B starts after A does
                i++;
            }
        }
        return result;
    }
};