/*
 * build a weighted-edge graph + Dijkstra Search
 * when building the graph, do not use a node class for the graph
 * instead, use a pair of <string, value>
 */
class Solution {
public:        
    double search(unordered_map<string, vector<pair<string, double>>>& dictionary, vector<string>& query){
        unordered_set<string> visited;
        string A = query[0], B = query[1];
        if (dictionary.find(A) == dictionary.end() || dictionary.find(B) == dictionary.end())
            return -1.0;
        priority_queue<pair<double,string>, vector<pair<double,string>>, greater<pair<double,string>>> que;
        que.push(make_pair(1.0, A));
        while(!que.empty() && visited.find(B) == visited.end()){
            auto tmp = que.top();
            que.pop();
            if (tmp.second == B)
                return tmp.first;
            visited.insert(tmp.second);
            for (auto p : dictionary[tmp.second]){
                if(visited.find(p.first) == visited.end()){
                    que.push(make_pair(tmp.first*p.second,p.first));
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> result;
        // build a weighted edge graph
        unordered_map<string, vector<pair<string, double>>> dictionary;
        for (int i = 0; i < equations.size(); i++){
            vector<string> eqn = equations[i];
            double val = values[i];
            // insert elements into the dictionary
            dictionary[eqn[0]].push_back(make_pair(eqn[1],val));
            dictionary[eqn[1]].push_back(make_pair(eqn[0],1/val));
        }
        // perform a DFS for each query
        for (auto query : queries){
            result.push_back(search(dictionary, query));
        }
        return result;
    }
};