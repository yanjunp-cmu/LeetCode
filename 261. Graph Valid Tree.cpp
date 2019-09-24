/*
 * DFS Method
 *
 * Similar to 207. Course Schedule
 * for undirected graph tree: we don't need to investigate every single node from scratch
 * undirectional offers a traversal capability to trace "parental" node
 *
 * what to check:
 *      for cyclic: if the node has been visited
 *                  not allowed to traverse back to parental node
 *      for tree: check if all nodes have been visited
 */


class Solution {
public:
    bool Cyclic(vector<vector<int>>& graph,
        vector<bool>& visited,
        int node,
        int parent) {
        // cycle if cisited
        if (visited[node])
            return true;
        // mark current point as visited
        visited[node] = true;
        
        for(auto it = graph[node].begin(); it != graph[node].end(); it++){
            if (*it != parent){
                if (Cyclic(graph, visited, *it, node))
                    return true;
            }
        }
        return false;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        // build an undirected graph
        for (vector<int> pair : edges){
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        // use the DFS method
        // when a node is visited, the graph contains a cycle
        // not allowed to go back the way it came from
        if(Cyclic(graph, visited, 0, n))
            return false;
        for (bool v : visited)
            if (!v) return false;
        return true;
    }
};

/*
 * BFS Method
 *
 * Similar to 207. Course Schedule
 * for undirected graph tree: we don't need to find a node with indegree of 1
 *
 * what to check:
 *      for cyclic: if the node has been visited
 *                  not allowed to traverse back to parental node
 *      for tree: check if all nodes have been visited
 */

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        
        // build an undirected graph
        for (vector<int> pair : edges){
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        // use the BFS method
        q.push(make_pair(0,-1));
        
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            visited[curr.first] = true;
            for (auto it = graph[curr.first].begin(); it != graph[curr.first].end(); it ++){
                if (*it != curr.second){
                    if (visited[*it])
                        return false;
                    q.push(make_pair(*it, curr.first));
                }
            }
        }
        for (bool v : visited)
            if (!v) return false;
        return true;
    }
};