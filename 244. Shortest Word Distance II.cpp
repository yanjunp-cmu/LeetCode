/*
    key point is the calculation of shortest distance
        two sorted vector
        min_dist = min(min_dist, abs(delta));
        if (vec1[i] < vec[2]) i++;
        else j++;
*/

class WordDistance {
private:
    map<string, vector<int> > dict;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++){
            if (dict.find(words[i]) == dict.end()){
                vector<int> pos = {i};
                dict[words[i]] = pos;
            } else {
                dict[words[i]].push_back(i);
            }
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> pos1 = dict[word1];
        vector<int> pos2 = dict[word2];
        int min_dist = INT_MAX;
        int i = 0, j = 0;
        while(i < pos1.size() && j < pos2.size()){
            min_dist = min(min_dist, abs(pos1[i] - pos2[j]));
            if (pos1[i] < pos2[j]){
                i++;
            } else {
                j++;
            }
        }
        return min_dist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */