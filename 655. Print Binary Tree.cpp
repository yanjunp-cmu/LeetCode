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
 * Procedure:
 *      1) get the total level of the tree
 *      2) run dfs to fill the table using bisecting indices
 */
class Solution {
public:
    int getHeight(TreeNode* root){
        if (!root)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    void fill(int left, int right, TreeNode* root, int depth, vector<vector<string>>& table){
        if (!root)
            return;
        int mid = left + (right - left)/2;
        table[depth][mid] = to_string(root->val);
        if (root->left)
            fill(left, mid - 1, root->left, depth + 1, table);
        if (root->right)
            fill(mid + 1, right, root->right, depth + 1, table);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> result;
        int height = getHeight(root);
        
        if (!height)
            return result;
        int width = pow(2, height) - 1;;
        result = vector<vector<string>> (height, vector<string>(width, ""));
        fill(0, width - 1, root, 0, result);
        return result;       
    }
};