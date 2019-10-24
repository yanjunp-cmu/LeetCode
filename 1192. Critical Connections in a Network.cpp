/*
 * Tarjan Algorithm
 *
 *  DFN[i]: search timestamp for node i
 *  LOW[i]: smallest root in the tree 
 *  https://blog.csdn.net/hurmishine/article/details/75248876
 */
class Solution {
private:
    vector<vector<int>> graph, result;
    vector<int> DFN, LOW;
    int timestamp = 0;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        DFN = vector(n, 0);
        LOW = vector(n, 0);
        graph.resize(n);
        // build graph
        for (int i = 0; i < connections.size(); i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        dfs(0, -1);
        return result;
    }
    
    void dfs(int cur, int pre) {
        if(DFN[cur] > 0) 
            return;
        DFN[cur] = LOW[cur] = ++timestamp;
        for(int next : graph[cur]) {
            if(next == pre) {
                continue;
            }
            dfs(next, cur);
            LOW[cur] = min(LOW[cur], LOW[next]);
            //
            if(LOW[next] > DFN[cur])
                result.push_back({cur, next});
        }
    }
};