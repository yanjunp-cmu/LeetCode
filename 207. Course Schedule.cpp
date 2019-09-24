/*
 * DFS solution
 * use two vector to keep track of the visited states
 * todo: for a path search
 * done: for global tracking
 * if a state is in done, then all its subpaths passed the test
 * if a state is in visited, then it has been visited for the current search branch
**/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        // build graph
        for (auto p : prerequisites){
            g[p[0]].push_back(p[1]);
        }
        // traverse through every starting point
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !acyclic(g, todo, done, i)) {
                return false;
            }
        }
        return true;
    }
private:  
    bool acyclic(vector<vector<int>>& g, vector<bool>& todo, vector<bool>& done, int node) {
        if (todo[node])
            return false;
        if (done[node])
            return true;
        todo[node] = true;
        done[node] = true;
        for (int v : g[node]) {
            if (!acyclic(g, todo, done, v)) {
                return false;
            }
        }
        todo[node] = false;
        return true;
    }
};