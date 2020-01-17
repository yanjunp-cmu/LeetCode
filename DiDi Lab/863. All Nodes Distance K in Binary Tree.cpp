/*
 * Approach: BFS
 * first traverse the tree to build a graph
 * then search the graph with BFS
 * keep a visited set to avoid revisiting nodes
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
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        // traverse the tree and build a graph
        unordered_map<int, vector<int>> graph;
        // BFS traversal of the tree
        queue<TreeNode*> tree_q;
        tree_q.push(root);
        while (!tree_q.empty()){
            TreeNode* tmp = tree_q.front();
            tree_q.pop();
            if (tmp->left){
                graph[tmp->val].push_back(tmp->left->val);
                graph[tmp->left->val].push_back(tmp->val);
                tree_q.push(tmp->left);
            }
            if (tmp->right){
                graph[tmp->val].push_back(tmp->right->val);
                graph[tmp->right->val].push_back(tmp->val);
                tree_q.push(tmp->right);
            }
        }
        // search the graph for nodes
        vector<int> result;
        queue<int> graph_q;
        unordered_set<int> visited;
        graph_q.push(target->val);
        int exp = 0;
        while(!graph_q.empty() && exp <= K){
            int size = graph_q.size();
            for (int i = 0; i < size; i++){
                int tmp = graph_q.front();
                graph_q.pop();
                                
                visited.insert(tmp);
                
                if (exp == K){
                    result.push_back(tmp);
                }
                
                for (auto successor : graph[tmp]){
                    if (visited.find(successor) == visited.end())
                        graph_q.push(successor);
                }               
            }
            exp++;
        }
        return result;
    }
};