/*
 * priority queue
 */
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        // use less comparator so that the maximum value is on the top
        priority_queue<vector<int>> pq; // height, right
        int ind_nb = 0, start_nb;       // index of the building
        while (ind_nb < buildings.size()){
            // intialize the pq
            if (pq.empty() && ind_nb < buildings.size()){
                start_nb = buildings[ind_nb][0];
                // push all buildings with the same starting index into the pq
                while (ind_nb < buildings.size() 
                       && buildings[ind_nb][0] == start_nb) {
                    pq.push({buildings[ind_nb][2], buildings[ind_nb][1]});
                    ind_nb++;
                }
                result.push_back({start_nb, (pq.top())[0]});
            }
            while (!pq.empty()){
                // add buildings that starts before top exits
                while (ind_nb < buildings.size() && 
                       (pq.top())[1] >= buildings[ind_nb][0]) {
                    pq.push({ buildings[ind_nb][2], buildings[ind_nb][1] });
                    // where the height increases
                    if ((result.back())[1] < (pq.top())[0])
                        result.push_back({ buildings[ind_nb][0], (pq.top())[0]});
                    ind_nb++;
                    // now (h.top())[1] has changed
                }
                // no more buildings to add, deal with the exit
                auto exit = pq.top();
                pq.pop();
                // only perserves the building with the rightmost corner
                while (!pq.empty() && (pq.top())[1] <= exit[1])
                    pq.pop();

                if (pq.empty())
                    result.push_back({exit[1], 0});
                else
                    result.push_back({exit[1], (pq.top())[0] });
            }
        } 
        return result;
    }
};


/*
 * segmented tree
 */
// Gets the max value in position at.
int get(const vector<int> &t, int at) {
    int n = t.size() / 2;
    int best = INT_MIN;
    for (at += n; at > 0; at >>= 1) {
        best = max(best, t[at]);
    }
    return best;
}

// Updates the interval [l, r).
void update(vector<int>& t, int l, int r, int value) {
    int n = t.size() / 2;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1){ 
            t[l] = max(t[l], value); 
            l++; 
        }
        if (r&1){ 
            --r; 
            t[r] = max(t[r], value); 
        }
    }
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<int> L(n), R(n), H(n), C;
        for (int i = 0; i < n; ++i) {
            const auto& b = buildings[i];
            L[i] = b[0];
            R[i] = b[1];
            H[i] = b[2];
            C.push_back(L[i]);
            C.push_back(R[i]);
        }
        sort(C.begin(), C.end());
        unique(C.begin(), C.end());
        int m = C.size();
        vector<int> tree(2*m, 0);

        for (int i = 0; i < n; ++i) {
            int l = lower_bound(C.begin(), C.end(), L[i]) - C.begin();
            int r = lower_bound(C.begin(), C.end(), R[i]) - C.begin();
            update(tree, l, r, H[i]);
        }

        vector<vector<int>> ans;
        for (int last = 0, i = 0; i < m; ++i) {
            int h = get(tree, i);
            if (h != last)
                ans.push_back({C[i], h});
            last = h;
        }
        return ans;
    }
};


/*
 * if no memory limit, works fine
 */
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        if(buildings.empty()) 
            return result;
        // preprocess to check alloc length
        int len = 0;
        for (auto it = buildings.begin(); it != buildings.end(); it++){
            len = max((*it)[1], len);
        }
        // first pass to get sillouette
        int count = 0;  // keep track of the right most edge
        vector<int> y_coord(len,0);
        for (auto it = buildings.begin(); it != buildings.end(); it++){
            count = max(count, (*it)[1]);
            for (int i = (*it)[0]; i < (*it)[1]; i++){
                y_coord[i] = max(y_coord[i], (*it)[2]);
            }
        }
        // second pass to grab key points
        int last = y_coord[buildings[0][0]];
        result.push_back({buildings[0][0], last});
        for (int i = buildings[0][0]; i <count;i++){
            int tmp = y_coord[i];
            if (tmp != last){
                result.push_back({i, tmp});
                last = tmp;
            }
        }
        result.push_back({count,0});
        return result;
    }
};