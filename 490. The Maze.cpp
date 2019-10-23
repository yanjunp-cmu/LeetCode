/*
 * BFS search (similar to Dijkstra Algorithm)
 */
class Solution {
private:
    int coord2ind(int x, int y, int x_size, int y_size){
        return (y * x_size) + x;
    }
    // returns true if out of bound
    bool isOut(int x, int y, int x_size, int y_size){
        return (x < 0 || x >= x_size || y < 0 || y >= y_size);
    }
    
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // right down left up
        vector<int> dirX = { 1, 0, -1,  0};
        vector<int> dirY = { 0, 1,  0, -1};
        int nR = maze.size(), nC = maze[0].size();
        
        vector<int> visited(nR*nC, 0);
        queue<pair<vector<int>,int>> maze_q;
        
        int start_idx = coord2ind(start[1], start[0], nC, nR);
        int dest_idx = coord2ind(destination[1], destination[0], nC, nR);
        
        // initialization
        for (int i = 0; i < 4; i++){
            int neiX = start[1] + dirX[i];
            int neiY = start[0] + dirY[i];
            if (!isOut(neiX, neiY, nC, nR) && maze[neiY][neiX] == 0){
                maze_q.push(make_pair(start, i));
            } 
        }
        visited[start_idx] = 1;
        while(!maze_q.empty() && visited[dest_idx] == 0){
            pair<vector<int>, int> p = maze_q.front();
            maze_q.pop();           
            
            // walk the point along the direction until hit a wall
            while(true){
                p.first[1] += dirX[p.second];
                p.first[0] += dirY[p.second];
                if(isOut(p.first[1],p.first[0], nC, nR)){
                    p.first[1] -= dirX[p.second];
                    p.first[0] -= dirY[p.second];
                    break;
                } else {
                    if(maze[p.first[0]][p.first[1]] == 1){
                        p.first[1] -= dirX[p.second];
                        p.first[0] -= dirY[p.second];
                        break;
                    }
                }
            }
            if (visited[coord2ind(p.first[1], p.first[0], nC, nR)] == 0){
                visited[coord2ind(p.first[1], p.first[0], nC, nR)] = 1;
                for (int i = 0; i < 4; i++){
                    int neiX = p.first[1] + dirX[i];
                    int neiY = p.first[0] + dirY[i];
                    if (!isOut(neiX, neiY, nC, nR) && maze[neiY][neiX] == 0){
                        vector<int> neiCoor = {neiY, neiX};
                        maze_q.push(make_pair(neiCoor, i));
                    } 
                }
            }
        }
        
        if (visited[dest_idx])
            return true;
        
        return false;
    }
};