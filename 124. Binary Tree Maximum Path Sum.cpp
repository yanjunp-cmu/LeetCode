/*
 * recursion
 * we need to find a maximum path sum
 * we can go from any node to another node following parent-child branch
 *
 * Normally, if we can only go from top to down, we return (root + max(left_sum, right_sum));
 * In this case, we need to consider the case we can traverse from the left branch to the right branch
 */

class Solution {
private:
	// max_sum keeps the max path sum resulted from paths crossing from left branch to the right
    int max_sum = INT_MIN;
public:
	int recursion(TreeNode* node){
		if (!node)
			return 0;
		int left_sum = max(recursion(node->left), 0);
		int right_sum = max(recursion(node->right), 0);
		int new_path_sum = node->val + left_sum + right_sum;
		max_sum = max(max_sum, new_path_sum);
		return node->val + max(left_sum, right_sum);
	}
	int maxPathSum(TreeNode* root) {
		return max(max_sum, recursion(root));
	}
};