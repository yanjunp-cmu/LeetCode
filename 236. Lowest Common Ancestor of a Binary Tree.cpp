/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
    basic idea: dfs
    if a node is null or p or q, return node
    if both return not null, LCA found
    if left is null, parents on the right
    if left is not null, parents on the left
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(root->val == p->val || root->val == q->val) return root;
        
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right ) return root;
        
        return left ? left : right;
    }
};
