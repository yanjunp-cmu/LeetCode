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
    void inorder_traversal(TreeNode* root, vector<int> &nums){
        if (!root)
            return;
        inorder_traversal(root->left, nums);
        nums.push_back(root->val);
        inorder_traversal(root->right, nums);
    }
    vector<int> SortByOneSwap(vector<int> nums){
        int x = -1, y = -1;
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i+1] < nums[i]){
                y = nums[i+1];
                if (x == -1)
                    x = nums[i];
                else
                    break;
            }
        }
        return {x,y};
    }
    void recoverTree(TreeNode* root) {
        // first use inorder traversal to extrace numbers into a list
        vector<int> nums;
        inorder_traversal(root, nums);
        // now, nums should be an almost sorted array with 2 misplaced item
        vector<int> misplaced = SortByOneSwap(nums);
        printf("misplaced: %d, %d\n", misplaced[0], misplaced[1]);
        int num1 = misplaced[0];
        int num2 = misplaced[1];
        // recover the tree
        queue<TreeNode*> recover_que;
        recover_que.push(root);
        int count = 2;
        while(!recover_que.empty() && count > 0){
            auto tmp = recover_que.front();
            recover_que.pop();
            if (tmp == NULL)
                continue;
            if (tmp->val == num1){
                tmp->val = num2;
                count --;
            } else if (tmp->val == num2){
                tmp->val = num1;
                count --;
            }
            recover_que.push(tmp->left);
            recover_que.push(tmp->right);
        }   
    }
};