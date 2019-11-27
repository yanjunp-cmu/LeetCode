/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
 * BFS:
 * use a map to keep track of visited nodes
 * the map can also be used to modify a copied node
 */
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        Node* copy = new Node(node->val, {});

        unordered_map<Node*, Node*> map;    // maps self to copy
        map[node] = copy;
        
        queue<Node*> que;
        que.push(node);
        while (!que.empty()){
            auto tmp = que.front();
            que.pop();
            for (auto nei : tmp->neighbors){
                // insert a neighbor is not seen, insert into the map first
                if (map.find(nei) == map.end()){
                    map[nei] = new Node(nei->val, {});
                    que.push(nei);                    
                }
                // modify the node linked with tmp
                map[tmp]->neighbors.push_back(map[nei]);
            }
        }
        return copy;
    }
};