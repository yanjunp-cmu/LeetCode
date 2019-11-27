/*
 * Dijkstra Algorithm
 * instead of the original Dijkstra Algorithm, this planner needs to search with expansion step
 * state = {city, expansion steps}
 *      i.e. {1, 0} = city 1 at 0 stops
             {1, 1} = city 1 at 1 stop
            are different states
 * the goal is to minimize cost from A to B
 * the priority_queue should be ordered around the cost
 *
 * the criteria to update visited set is such that if the top node is less than
 num of stops, mark as visited
 */
class Solution {
public:
    struct mycomp{
        bool operator()(vector<int> &A, vector<int> &B){
            return A[1] >= B[1];
        }  
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K){
        unordered_map<int, vector<vector<int>>> graph;
        vector<int> cost(n, INT_MAX);
        vector<vector<int>> visited(n, vector<int>(K+1, 0));
        // explicitly build a graph
        for (auto edge : flights){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        // initialize for a search
        cost[src] = 0;
        // one element in pq represents {city, cost, expansions}
        priority_queue<vector<int>, vector<vector<int>>, mycomp> que;
        que.push({src, cost[src], -1});
        while (!que.empty() && accumulate(visited[dst].begin(), visited[dst].end(), 0) == 0){
            auto tmp = que.top();
            que.pop();
            // goal reached
            if (tmp[0] == dst && tmp[2] <= K)
                return tmp[1];
            // if not visited 
            if (!visited[tmp[0]][tmp[2] < 0? K:tmp[2]]){
                if (tmp[2] <= K){
                    if (tmp[2] < 0)
                        visited[tmp[0]][K] = 1;
                    else
                        visited[tmp[0]][tmp[2]] = 1;
                }
                for (auto edge : graph[tmp[0]]){
                    if (tmp[2] < K && !visited[edge[0]][tmp[2] + 1]){
                        cost[edge[0]] = tmp[1] + edge[1];
                        que.push({edge[0], cost[edge[0]], tmp[2] + 1});
                    }
                }
            }
        }
        return -1;
    }
};