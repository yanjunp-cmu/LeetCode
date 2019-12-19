/*
 * Method 1: Brute Force (DFS)
 * time limit exceeds
 * possible actions: add the element to the existing list
 *                   start a new list from the element
 * return criteria: when the we finish iterate the vector and the count of subarray is m
 */
class Solution {
public:
    int ans;
    int n, m;
    void dfs(vector<int>& nums, int i, int cntSubarrays, int curSum, int curMax) {
        if (i == n && cntSubarrays == m) {
            ans = min(ans, curMax);
            return;
        }
        if (i == n) {
            return;  
        }
        if (i > 0) {
            dfs(nums, i + 1, cntSubarrays, curSum + nums[i], max(curMax, curSum + nums[i]));
        }
        if (cntSubarrays < m) {
            dfs(nums, i + 1, cntSubarrays + 1, nums[i], max(curMax, nums[i]));
        }
    }
    int splitArray(vector<int>& nums, int M) {
        ans = INT_MAX;
        n = nums.size();
        m = M;
        dfs(nums, 0, 0, 0, 0);
        return ans;
    }
};

/*
 * DP solution
 * O(mn^2)
 * where dp[i][j] is the optimal result for splitting nums[:i+1] into j subarrays
 * subproblem: split j numbers into i subgroups
 */
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        vector<long> sub(n+1,0);
        for(int i = 0; i < n; i++){ // a vector initialized to a one interval subarray
            sub[i+1] = sub[i] + nums[i];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                for (int k = 0; k < i; k++){
                    // sub[i] - sub[k] == accumulate sum between i-th and k-th element
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], (int) (sub[i] - sub[k])));
                }
            }   
        }
        return dp[n][m];
    }
};

/*
 * Greedy + binary search
 * https://leetcode.com/problems/split-array-largest-sum/discuss/89819/C%2B%2B-Fast-Very-clear-explanation-Clean-Code-Solution-with-Greedy-Algorithm-and-Binary-Search
 */
 class Solution {
private:
    bool doable (const vector<int>& nums, int cuts, long long max) {
        long acc = 0;
        for (int num : nums) {
            // This step is unnecessary for this problem. I didn't discard this line because I want doable function more generalized.
            if (num > max) return false;
            else if (acc + num <= max) 
                acc += num;
            else {
                --cuts;
                acc = num;
                if (cuts < 0) return false;
            }
        }
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (int num : nums) {
            left = max(left, (long long)num);
            right += num;
        }
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (doable(nums, m - 1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};