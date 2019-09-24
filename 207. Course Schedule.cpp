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



/*
 * BFS solution
 * use indegree topological sort
 * a vector of int keeps record of the in-degree of a course
 *      that is how many times this course appears as a prerequisite
 * graph is constructed such that g[k] is all courses use k as prerequisite
 *
 * main loop:
 *      decrease indegree of a node 
 *      push into the queue if indegree is zero
 *
 * final checking condition: the number of courses visited and the total number of courses
**/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> degrees(numCourses);
        // build a graph
        for (auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        // compute indegree
        for (auto adj : g)
            for (int d : adj)
                degrees[d]++;
        
        // bfs
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()){
            int tmp = q.front();
            q.pop();
            count++;
            for (auto it = g[tmp].begin(); it != g[tmp].end(); it++){
                degrees[*it]--;
                if (degrees[*it] == 0) 
                    q.push(*it);
            }
        }
        return count == numCourses;
    }
};