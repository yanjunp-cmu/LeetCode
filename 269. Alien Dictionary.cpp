/*
 * topo sort
**/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 1) {
            return words[0];
        }
        graph g = buildGraph(words);
        unordered_map<char, int> degrees = computeIndegrees(g);
        int numNodes = degrees.size();
        string order;
        queue<char> toVisit;
        for (auto node : degrees) {
            if (!node.second) {
                toVisit.push(node.first);
            }
        }
        for (int i = 0; i < numNodes; i++) {
            if (toVisit.empty()) {
                return "";
            }
            char c = toVisit.front();
            toVisit.pop();
            order += c;
            for (char neigh : g[c]) {
                if (!--degrees[neigh]) {
                    toVisit.push(neigh);
                }
            }
        }
        return order;
    }
private:
    typedef unordered_map<char, unordered_set<char>> graph;
    
    graph buildGraph(vector<string>& words) {
        graph g;
        int n = words.size();
        for (int i = 1; i < n; i++) {
            bool found = false; // flag for first different character
            string word1 = words[i - 1], word2 = words[i];
            int m = word1.size(), n = word2.size(), l = max(m, n);
            for (int j = 0; j < l; j++) {
                if (j < m && g.find(word1[j]) == g.end()) {
                    g[word1[j]] = {};
                }
                if (j < n && g.find(word2[j]) == g.end()) {
                    g[word2[j]] = {};
                }
                if (j < m && j < n && word1[j] != word2[j] && !found) {
                    g[word1[j]].insert(word2[j]);
                    found = true;
                }
            }
        }
        return g;
    }
    
    unordered_map<char, int> computeIndegrees(graph& g) {
        unordered_map<char, int> degrees;
        for (auto adj : g) {
            degrees[adj.first];
            for (char neigh : adj.second) {
                degrees[neigh]++;
            }
        }
        return degrees;
    }
};