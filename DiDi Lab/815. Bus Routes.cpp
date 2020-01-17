/*
 * BFS with purning
 */
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T)
            return 0;

        // build the stop-routes dictionary
        unordered_map<int, unordered_set<int>> stoproutes;
        for (int i = 0; i < routes.size(); i++)
            for (int j : routes[i])
                stoproutes[j].insert(i);

        vector<bool> vr(routes.size()); // visited routes
        vector<int> stops{S}; // act like a queue but easier and slightly faster

        for (int cnt = 1; !stops.empty(); cnt++) {
            vector<int> tmp; // temporary working set
            for (int i : stops) // for each stop in current working set
            for (int j : stoproutes[i]) // for each route at the stop
                if (!vr[j]) { // pruning
                    vr[j] = true;
                    for (int k : routes[j]) { // for each stop in the route
                        if (k == T)
                            return cnt;
                        tmp.push_back(k);
                    }
                }
            swap(tmp, stops);
        }

        return -1;
    }
};

/*
 * Approach: BFS
 * use route numbers as search nodes instead of stop numbers
 */
class Solution {
private: 
    // use double pointer to check if two vectors have intersections
    bool isIntersect(vector<int>& routeA, vector<int>& routeB){
        sort(routeA.begin(), routeA.end());
        sort(routeB.begin(), routeB.end());
        int i = 0, j = 0;
        while (i < routeA.size() && j < routeB.size()){
            if (routeA[i] == routeB[j])
                return true;
            if (routeA[i] < routeB[j])
                i++;
            else 
                j++;
        }
        return false;
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) 
            return 0;
        
        int N = routes.size();
        
        // create a hashmap: key-stop, value-route number
        map<int, vector<int>> stop_map;
        for (int i = 0; i < N; i++){
            for (int stop : routes[i]){
                stop_map[stop].push_back(i);
            }
        }
        
        // create a start set and a goal set
        vector<int> start = stop_map[S];
        unordered_set<int> goal;
        for (int stop : stop_map[T])
            goal.insert(stop);
        
        // build a graph and use routes as graph nodes
        map<int, unordered_set<int>> graph;
        for (int i = 0; i < N; i++){
            for (int j = i+1; j < N; j++){
                if (isIntersect(routes[i], routes[j])){
                    graph[i].insert(j);
                    graph[j].insert(i);   
                }
            }
        }
        
        // keep track of the visited set to prevent going back and forth
        vector<int> visited(N, 0);
        
        // BFS here
        queue<int> q;
        for (int s:start) {
            q.push(s);
        }
        int res = 1;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                int tmp = q.front();
                q.pop();
                
                if (visited[tmp])
                    continue;
                
                if (goal.find(tmp) != goal.end())
                    return res;
                
                visited[tmp] = 1;
                
                for (int successor : graph[tmp]){
                    if (!visited[successor])
                        q.push(successor);
                }
            }
            res++;
        }
        
        return -1;
    }
};