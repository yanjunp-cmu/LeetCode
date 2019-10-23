/*
 * Union Find
 */



/*
 * DFS solution
 */
class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<int>& visited, int cur){
        visited[cur] = 1;
        for (int i = 0; i < M.size(); i++){
            if (M[cur][i] && !visited[i]){
                dfs(M, visited, i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty())
            return 0;
        
        int N = M.size();
        int result = 0;
        vector<int> visited(N, 0);
        for(int i = 0; i < N; i++){
            if (visited[i])
                continue;
            result++;
            dfs(M, visited, i); 
        }
        return result;
    }
};

/*
 * BFS solution
 */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty())
            return 0;
        
        int N = M.size();
        int result = 0;
        vector<int> visited(N, 0);
        queue<int> bfs_q;
        
        for (int i = 0; i < N; i++){
            if (visited[i])
                continue;
            bfs_q.push(i);
            result++;
            // bfs here
            while (!bfs_q.empty()){
                int tmp = bfs_q.front();
                bfs_q.pop();
                if (!visited[tmp]){
                    visited[tmp] = 1;
                    
                    for (int j = 0; j < N; j++){
                        if(j != i && M[tmp][j] == 1){
                            bfs_q.push(j);
                        }
                    }
                }
            }
        }
        return result;
    }
};