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
 * preorder provides node that in the inorder vector separates the vector into left and right subtree
 * use a map: key-value, value-position in inorder
 */
class Solution {
private:
    int pre_idx;
    map<int, int> inorder_map;
    
    TreeNode* helper(int left, int right, vector<int>& preorder, vector<int>& inorder){
        if (left > right || left < 0 || right >= inorder.size())
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[pre_idx]);
        int cur_idx = inorder_map[root->val];
        pre_idx++;
        // build the left branch
        root->left = helper(left, cur_idx - 1, preorder, inorder);
        // build the right branch
        root->right = helper(cur_idx + 1, right, preorder, inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // initialize
        pre_idx = 0;
        // the map contains values as keys and indices in inorder as value
        int i = 0;
        for (int val : inorder){
            inorder_map[val] = i;
            i++;
        }
        // the tree built
        return helper(0, preorder.size()-1, preorder, inorder);
    }
};