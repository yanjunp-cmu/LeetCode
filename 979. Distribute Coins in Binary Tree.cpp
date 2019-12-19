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
 * If the leaf of a tree has 0 coins (an excess of -1 from what it needs), 
 * then we should push a coin from its parent onto the leaf. 
 * If it has say, 4 coins (an excess of 3), 
 * then we should push 3 coins off the leaf. 
 * In total, the number of moves from that leaf to or from its parent is excess = Math.abs(num_coins - 1). 
 * Afterwards, we never have to consider this leaf again in the rest of our calculation.
 */

class Solution {
private:
    int ans;
public:
    int dfs(TreeNode* root){
        if (!root)
            return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        ans += (abs(L) + abs(R));
        return root->val + L + R - 1;
    }
    int distributeCoins(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};