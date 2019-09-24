/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void SumBST(TreeNode* root, int *count, int L, int R)
    {
        if(root == NULL)
            return;
        
        if(root->val >= L && root->val <= R)
            *count += root->val;
        
        SumBST(root->left, count, L, R);
        SumBST(root->right, count, L, R);
        
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        SumBST(root, &sum, L, R);
        
        return sum;
        
    }
};