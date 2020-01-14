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
	dfs approach:
	if the currentNode is NULL, then nodes p and q are not found in its branch
	
	three flags:
		left: one of the node is found in the left branch
		right: one of the node is found in the right branch
		mid: current node is either p or q node
	
	if the number of flags being true is at least 2, then the currentNode is the LCA
*/
class Solution {
private:
    TreeNode* ans = NULL;
    bool recurseTree(TreeNode* currentNode, TreeNode* p, TreeNode* q){
        if (!currentNode)
            return false;
        int left = recurseTree(currentNode->left, p, q)? 1 : 0;
        int right = recurseTree(currentNode->right, p, q)? 1 : 0;
        int mid = (currentNode == p || currentNode == q)? 1 : 0;
        if (mid + left + right >= 2)
            ans = currentNode;
        return (mid + left + right > 0);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (recurseTree(root, p, q))
            return ans;
        else
            return NULL;
    }
};




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
 * iterate with parent pointer (dfs for path approach)
 */
class Solution {
private:
    unordered_map<int, TreeNode*> parent_map;
    vector<TreeNode*> p_path, q_path;
    bool p_found = false, q_found = false;
    
    void backtrack(vector<TreeNode*>& path, TreeNode* node){
        path.push_back(node);
        if (parent_map.find(node->val) == parent_map.end())
            return;
        backtrack(path, parent_map[node->val]);
    }
    
    
    void recurseTree(TreeNode* currentNode, TreeNode* p, TreeNode* q, TreeNode* lastNode){
        if (!currentNode)
            return;
        
        if (lastNode)
            parent_map[currentNode->val] = lastNode;
        
        if (currentNode == p){
            backtrack(p_path, p);
            p_found = true;
        }
        
        if (currentNode == q){
            backtrack(q_path, q);
            q_found = true;
        }
        
        if (p_found && q_found){
            return;
        }
        
        recurseTree(currentNode->left, p, q, currentNode);
        recurseTree(currentNode->right, p, q, currentNode);
        return;
    }
    
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recurseTree(root, p, q, NULL);

        // find the LCA from two vectors
        int p_path_len = p_path.size();
        int q_path_len = q_path.size();
        
        int i = 0, j = 0;
        
        while (i < p_path_len && j < q_path_len){
            if (p_path[i] == q_path[j])
                return p_path[i];
            int remain_p = p_path_len - i;
            int remain_q = q_path_len - j;
            
            
            if (remain_p < remain_q){
                j++;
            } else if (remain_p > remain_q){
                i++;
            } else {
                i++;
                j++;
            }
        }
        
        return NULL;
    }
};