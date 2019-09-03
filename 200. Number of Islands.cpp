/*
    DFS
*/
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int nR = grid.size(), nC = grid[0].size();
        // indicate visited by turning '1' to '0'
        grid[i][j] = '0';
        // check up
        if (i - 1 >= 0 && grid[i-1][j] == '1') dfs(grid, i - 1, j);
        // check down
        if (i + 1 < nR && grid[i+1][j] == '1') dfs(grid, i + 1, j);
        // check left    
        if (j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        // check right
        if (j + 1 < nC && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.empty()) return res;
        int nR = grid.size(), nC = grid[0].size();
        for (int i = 0; i < nR; i++){
            for (int j = 0; j < nC; j++){
                // if grid[i][j] is '1', there is at least one island
                if (grid[i][j] == '1'){                    
                    res++;
                    dfs(grid, i, j);
                }
                
            }
        }
        return res;
    }
};

/*
    BFS
    requires a queue to store qualified node
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.empty()) return res;
        
        queue<pair<int,int>> bfs_q;
        
        int nR = grid.size(), nC = grid[0].size();
        
        for (int i = 0; i < nR; i++){
            for (int j = 0; j < nC; j++){
                if (grid[i][j] == '1'){                    
                    res++;
                    bfs_q.push({i,j});
                    while(!bfs_q.empty()){
                        auto root = bfs_q.front();
                        bfs_q.pop();
                        int row = root.first, col = root.second;
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            bfs_q.push({row-1, col}); 
                            grid[row-1][col] = '0';
                        }
                        if (row + 1 < nR && grid[row+1][col] == '1') {
                            bfs_q.push({row+1, col}); 
                            grid[row+1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            bfs_q.push({row, col-1}); 
                            grid[row][col-1] = '0';
                        }
                        if (col + 1 < nC && grid[row][col+1] == '1') {
                            bfs_q.push({row, col+1}); 
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return res;
    }
};

/*
    Union Find
*/
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        //first convert to 1 dimension position, and convert all connections to edges
        vector<pair<int, int> >edges;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int id = i * n + j;
                    //go right
                    if (j + 1 < n) {
                        if (grid[i][j+1] == '1') {
                            int right = i * n + j + 1;
                            edges.push_back(make_pair(id, right));
                        }
                    }
                    //go down
                    if (i + 1 < m) {
                        if (grid[i+1][j] == '1') {
                            int down = (i + 1) * n + j;
                            edges.push_back(make_pair(id, down));
                        }
                    }
                }
            }
        }
        
        // First construct the Union Find structure
        // vector value is itself
        vector<int> hashSet(m * n, 0);
        for (int i = 0; i < m * n; i++) {
            hashSet[i] = i;
        }
        
        //Next Union Find
        for (auto edge : edges) {
            Union(hashSet, edge.first, edge.second);
        }
        
        int numComponents = 0;
        for (int i = 0; i < m * n; i++) {
            if ( grid[i / n][i % n] == '1' && hashSet[i] == i)
                numComponents++;
        }
        
        return numComponents;
    }
    
    void Union(vector<int>& hashSet, int first, int second) {
        int first_father = Find(hashSet, first);
        int second_father = Find(hashSet, second);
        
        if (first_father != second_father)
            hashSet[first_father] = second_father;
    }
    
    int Find(vector<int>& hashSet, int val) {
        int parent = val;
        while (parent != hashSet[parent]) {
            parent = hashSet[parent];
        }
        return parent;
    }
};