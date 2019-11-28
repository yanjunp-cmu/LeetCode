/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
 * queue method:
 * update level order from left to right 
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> rightmostValueAtDepth; // key is depth, value is node value
        int max_depth = -1;
        queue<TreeNode*> nodeQueue;
        queue<int> depthQueue;
        // initialize the search
        nodeQueue.push(root);
        depthQueue.push(0);
        while(!nodeQueue.empty()){
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            int depth = depthQueue.front();
            depthQueue.pop();
            if (node){
                rightmostValueAtDepth[depth] = node->val;
                nodeQueue.push(node->left);
                nodeQueue.push(node->right);
                depthQueue.push(depth + 1);
                depthQueue.push(depth + 1);   
            }
        }
        vector<int> result;
        for (auto it = rightmostValueAtDepth.begin(); it!=rightmostValueAtDepth.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
};
/*
 * BFS METHOD
 * key take away:
 *      level order traversal of the tree
 *      use an inner loop to traverse over one level
 *      push sub-level into queue
**/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        if(!root) return result;
        queue<TreeNode*> bfs_q;
        bfs_q.push(root);
        int q_depth = 0;
        while (!bfs_q.empty()){
            int q_size = bfs_q.size();
            result.push_back(bfs_q.front()->val);
            while (q_size){
                TreeNode* tmp = bfs_q.front();
                bfs_q.pop();
                if (tmp->right)  bfs_q.push(tmp->right);
                if (tmp->left)  bfs_q.push(tmp->left);
                q_size--;
            }            
        }
        return result;
    }
};


/*
 * DFS METHOD
**/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        rightView(root, view, 0);
        return view;
    }
private:
    void rightView(TreeNode* root, vector<int>& view, int level) {
        if (!root) {
            return;
        }
        if (view.size() == level) {
            view.push_back(root -> val);
        }
        rightView(root -> right, view, level + 1);
        rightView(root -> left,  view, level + 1);
    }
};