/*
 * Bi-directional BFS
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // if the endWord is not in the wordList
        if(wordSet.find(endWord) == wordSet.end()) 
            return 0;

        unordered_set<string> s1, s2;
        s1.insert(beginWord);
        s2.insert(endWord);
        int ans = 1;

        while(!s1.empty() && !s2.empty()){
            ans++;
            if(s1.size() > s2.size()) 
                swap(s1, s2);
            unordered_set<string> temp;
            for(auto it = s1.begin(); it != s1.end(); it++){
                string w = *it;
                for(int i = 0; i < w.size(); i++){
                    char c = w[i];
                    // change one character at a time and see
                    for(int j = 0; j < 26; j++){
                        w[i] = 'a' + j;
                        if(s2.find(w) != s2.end()) 
                            return ans;
                        // if the alternate exists in the wordSet, add into wordSet
                        if(wordSet.find(w) != wordSet.end()){
                            temp.insert(w);
                            wordSet.erase(w);
                        }
                    }
                    w[i] = c;
                }
            }
            swap(s1, temp);
        }
        return 0;
    }
};


/*
 * SLOWWWWWWW
 * build an non-directional graph and search
 */
class Solution {
public:
    bool isConnection(string A, string B){
        int count = 0;
        int i = 0;
        while (count < 2 && i < A.size()){
            if (A[i] != B[i]){
                count++;
            }
            i++;
        }
        if (count > 1)
            return false;
        return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 0;
        unordered_map<string, vector<string>> graph;
        wordList.push_back(beginWord);
        // build a graph   
        for (int i = 0; i < wordList.size() - 1; i++){
            for (int j = i+1; j < wordList.size(); j++){
                if (isConnection(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        // search the graph for potential solution
        if (graph.find(endWord) == graph.end())
            return 0;
        
        set<string> visited;
        queue<string> bfs_q;
        bfs_q.push(endWord);
        
        while (!bfs_q.empty() && (visited.find(beginWord) == visited.end())){
            int count = bfs_q.size();
            for (int i = 0; i < count; i++){
                string tmp = bfs_q.front();
                bfs_q.pop();
                visited.insert(tmp);
                for (auto it = graph[tmp].begin(); it != graph[tmp].end(); it++){
                    if(visited.find(*it) == visited.end()){
                        bfs_q.push(*it);
                    }
                }
            }
            res++;
        }
        
        if(visited.find(beginWord) != visited.end())
            return res;
        else 
            return 0;
    }
};