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
 * DFS: 
 * always select the mid as the root and separate the left and right subtree
 * return condition: left > right
 */
class Solution {
public:
    TreeNode* helper(int left, int right, vector<int>& nums){
        if (left > right)
            return NULL;
        int mid = (left + right)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(left, mid-1, nums);
        root->right = helper(mid+1, right, nums);
        return root;        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0, nums.size()-1, nums);
    }
};