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
    int calc_height(TreeNode* root){
        if (!root)
            return -1;
        return 1 + max(calc_height(root->left), calc_height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return abs(calc_height(root->left)-calc_height(root->right)) < 2 &&
                isBalanced(root->left) && isBalanced(root->right);
    }
};