/*
 * BFS/ dp
 */
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty()) return false;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); // dist[i][j] maintain the shortest distance from start to (i,j)
        queue<pair<int,int>> q; // {i*n+j, dist}
        int go[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        q.push({start[0]*n + start[1], 0});
        dist[start[0]][start[1]] = 0;
        while (!q.empty()) {
            int i = q.front().first/n, j = q.front().first%n;
            int t = q.front().second; // distance
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i, nj = j;
                int s = 0;
                while (ni >= 0 && ni < m && nj >= 0 && nj < n && maze[ni][nj] == 0) {
                    ni += go[d][0]; nj += go[d][1]; ++s;
                }
                ni -= go[d][0]; nj -= go[d][1]; --s;
                if (t+s >= dist[ni][nj]) continue; // if this is a longer path, no need to move on
                else {
                    dist[ni][nj] = t+s;
                    if (ni != destination[0] || nj != destination[1]) q.push({ni*n + nj, t+s});
                }
            }
        }
        return dist[destination[0]][destination[1]] == INT_MAX ? -1 : dist[destination[0]][destination[1]];
    }
};

/*
 * Dijkstra 
 */
class Solution {
private:
    struct TupleCompare{
        bool operator()(const tuple<vector<int>,int,int>& A, const tuple<vector<int>,int,int>& B){
            return get<2>(A) > get<2>(B);
        }
    };
    int coord2ind(int x, int y, int x_size, int y_size){
        return (y * x_size) + x;
    }
    // returns true if out of bound
    bool isOut(int x, int y, int x_size, int y_size){
        return (x < 0 || x >= x_size || y < 0 || y >= y_size);
    }
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int nR = maze.size(), nC = maze[0].size();
        // initialize a cost map
        vector<vector<int>> cost(nR,vector<int>(nC, 2* (nC + nR)));
        cost[start[0]][start[1]] = 0;
        
        // right, down, left, up
        vector<int> dirX = { 1,  0, -1,  0};
        vector<int> dirY = { 0,  1,  0, -1};
        
        // define priority_queue for the Dijkstra Algorithm
        priority_queue<tuple<vector<int>,int,int>, vector<tuple<vector<int>,int,int>>, TupleCompare> maze_q;
        
        int start_idx = coord2ind(start[1], start[0], nC, nR);
        int dest_idx = coord2ind(destination[1], destination[0], nC, nR);
        
        // initialize the queue
        for (int i = 0; i < 4; i++){
            int neiX = start[1] + dirX[i];
            int neiY = start[0] + dirY[i];
            if (!isOut(neiX, neiY, nC, nR) && maze[neiY][neiX] == 0){
                maze_q.push(make_tuple(start, i, cost[start[0]][start[1]]));
            } 
        }
        
        // each grid can have 4 state 
        vector<vector<int>> visited(nR*nC, vector<int>(4,0));
        
        while(!maze_q.empty() && !any_of(visited[dest_idx].begin(), visited[dest_idx].end(), [](int i){return i == 1;})){
            cout << "pq size: " << maze_q.size() << endl;
            auto p = maze_q.top();
            maze_q.pop();  
            
            // extract information from p
            vector<int> p_coord = get<0>(p);
            int p_dir           = get<1>(p);
            int p_cost          = get<2>(p);
            int p_ind           = coord2ind(p_coord[1], p_coord[0], nC, nR);
                       
            if (!visited[p_ind][p_dir]){
                visited[p_ind][p_dir] = 1;
                // walk the point along the direction until hit a wall
                int steps = 0;
                while(true){
                    steps++;
                    p_coord[1] += dirX[p_dir];
                    p_coord[0] += dirY[p_dir];
                    if(isOut(p_coord[1],p_coord[0], nC, nR) || (!isOut(p_coord[1],p_coord[0], nC, nR) && (maze[p_coord[0]][p_coord[1]] == 1))){
                        steps--;
                        p_coord[1] -= dirX[p_dir];
                        p_coord[0] -= dirY[p_dir];
                        break;
                    }
                }
                p_cost = p_cost + steps;
                cout << "visited coordinate: "<< p_coord[0] << "," << p_coord[1] << " direction: "<< p_dir << endl;
                // cout << "cost is: " << p_cost << endl;
                if(cost[p_coord[0]][p_coord[1]] > p_cost){
                    cost[p_coord[0]][p_coord[1]] = p_cost;
                    for(int i = 0; i < 4; i++){
                        int neiX = p_coord[1] + dirX[i];
                        int neiY = p_coord[0] + dirY[i];
                        // cout << "neighbor coordinate: "<< neiY << "," << neiX << " direction: "<< i << endl;
                        if(!isOut(neiY, neiX, nC, nR) && (maze[neiY][neiX] == 0)){
                            maze_q.push(make_tuple(p_coord, i, p_cost));
                        }
                    }
                }
            }
        }
        
        if (any_of(visited[dest_idx].begin(), visited[dest_idx].end(), [](int i){return i == 1;}))
            return cost[destination[0]][destination[1]];
        
        return -1;
    }
};