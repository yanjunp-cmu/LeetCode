class Solution {
private:
    int check(int x, vector<int>& A, vector<int>& B){
        int rotations_a = 0, rotations_b = 0;
        for (int i = 0; i < A.size(); i++){
            if (A[i] != x && B[i] != x)
                return -1;
            else if (A[i] != x)
                rotations_a++;
            else if (B[i] != x)
                rotations_b++;
        }
        return min(rotations_a, rotations_b);
    }
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        // greedy solution
        // tries to make all numbers in A equal to A[0]
        int rotations = check(A[0], A, B);
        if (rotations != -1 || A[0] == B[0])
            return rotations;
        else 
            // tries to make all numbers in A equal to B[0]
            return check(B[0], A, B);
    }
};