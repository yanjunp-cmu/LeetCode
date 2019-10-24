/*
 * Union Find
 */
class Solution {
public:
    int Find(vector<int> parent, int i){
        if (parent[i] == -1)
            return i;
        return Find(parent, parent[i]);
    }
    
    void Union(vector<int>& parent, int x, int y){
        int xset = Find(parent, x);
        int yset = Find(parent, y);
        if (xset != yset)
            parent[xset] = yset;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int result = 0;
        int N = M.size();
        vector<int> union_vec(N, -1);
        
        // start union process
        for (int i = 0; i <N; i++){
            for (int j = 0; j<N; j++){
                if (M[i][j] && i != j){
                    Union(union_vec, i, j);
                }
            }
        }
        
        for (int i = 0; i < N; i++)
            if (union_vec[i] == -1)
                result++;
        
        return result;;
    }
};


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