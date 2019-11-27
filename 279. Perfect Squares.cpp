/*
 * BFS:
 * calculate all components first
 * push all components into a queue and perform bfs
 */
class Solution {
public:
    int numSquares(int n) {
        vector<int> components;
        int result = 1;
        // construct a list of perfect squares less than n
        for (int i = 1; i <= n; i++){
            if (i*i < n)
                components.push_back(i*i);
            else if (i*i == n)
                return 1;
            else
                break;
        }
        // BFS with layer number
        queue<int> que;
        for (int comp : components){
            que.push(comp);
        }
        while(!que.empty()){
            int size = que.size();
            result ++;
            for (int i = 0; i < size; i++){
                int tmp = que.front();
                que.pop();
                for (int comp : components){
                    if (tmp + comp < n){
                        que.push(tmp + comp);
                    } else if (tmp + comp == n){
                        return result;
                    }
                }
            }
        }
        return 0;
    }
};

/*
 * DP formulation:
 * equivalent to a coin change problem
 */
class Solution {
public:
    int numSquares(int n) {
        vector<int> components;
        int result = 1;
        // construct a list of perfect squares less than n
        for (int i = 1; i <= n; i++){
            if (i*i < n)
                components.push_back(i*i);
            else if (i*i == n)
                return 1;
            else
                break;
        }
        // transfer into a DP problem
        // DP i means the minimum used at i-th number
        vector<int> dp(n+1, 0);
        for (int i = 1; i < dp.size(); i++){
            auto upp = upper_bound(components.begin(), components.end(), i);
            
            int min_cnt = INT_MAX;
            for (auto j = components.begin(); j<upp; j++){
                min_cnt = min(min_cnt, dp[i - *j]);
            }
            dp[i] = 1 + min_cnt;
        }
        return dp[dp.size()-1];        
    }
};