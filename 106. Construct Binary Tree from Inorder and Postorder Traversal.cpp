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
 * postorder has root information from the rear
 * root separate inorder list into left and right trees
 */

class Solution {
private:
    unordered_map<int, int> inorderHash;
    
    TreeNode* buildTreeHelper(vector<int>& inorder, int inLeft, int inRight, 
                              vector<int>& postorder, int* postRight) {
        if (inLeft > inRight) {
            return NULL; // subtree is empty.
        }
        
        int rootVal = postorder[*postRight];
        TreeNode* root = new TreeNode(rootVal);
        
        int inIndx = inorderHash[rootVal];
        (*postRight)--;
        // Construct right subtree.
        root->right = buildTreeHelper(inorder, inIndx+1, inRight, postorder, postRight);
        //Construct left subtree.
        root->left = buildTreeHelper(inorder, inLeft, inIndx-1, postorder, postRight);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inSize = inorder.size();
        int postSize = postorder.size()-1;
        
        if (inSize == 0 || postSize < 0) {
            return NULL;
        }
        
        for (int i = 0; i < inSize; ++i) {
            inorderHash[inorder[i]] = i; // value->index
        }
        
        return buildTreeHelper(inorder, 0, inSize-1, 
                               postorder, &postSize);
    }
};