/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
 * Convert the singly linked list into an array first
 * Recursion by dividing the problem into two subproblems: left sub-branch and right sub-branch
 *      stopping criteria: left > right
 *      if (left == right) return node
 *      node->left  = recursion(nums, left,  mid-1)
 *      node->right = recursion(nums, mid+1, right)
 */
class Solution {
public:
    TreeNode* recursion(vector<int> nums, int left, int right){
        if (left > right)
            return NULL;
        int mid = left + (right - left)/2;
        TreeNode *result = new TreeNode(nums[mid]);
        if (left == right)
            return result;
        result->left = recursion(nums, left, mid - 1);
        result->right = recursion(nums, mid + 1, right);
        return result;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // convert the singly linked list into a vector of numbers
        vector<int> numbers;
        for (ListNode* tmp = head; tmp != NULL; tmp = tmp->next){
            numbers.push_back(tmp->val);
        }
        if (numbers.size() == 0)
            return NULL;
        return recursion(numbers, 0, numbers.size() - 1);
    }
};