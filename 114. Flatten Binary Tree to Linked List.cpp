/*
 * DFS method:
 * bring all left sub trees to order first
 * append right sub tree to the original left ones
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        helper(root); 
    }
    TreeNode* helper(TreeNode* n){
        if(!n) return NULL;
        if(n->left){
            TreeNode* right_child = n->right;
            n->right = n->left;
            n->left = NULL;
            TreeNode* tail = helper(n->right);
            tail->right = right_child;
            return tail->right? helper(tail->right) : tail;
        }
        else{
            return n->right? helper(n->right) : n;
        }
    }
};