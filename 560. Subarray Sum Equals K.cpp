/* Method 1: Cumulative Sum */
// time complexity O(n^2)
// space complexity O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        if (nums.empty()) return 0;
        
        // use a vector to store cumulative sum upto i-th index
        vector<int> cum_sum(nums.size(),0);
        cum_sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++){
            cum_sum[i] = cum_sum[i-1] + nums[i];
        }
        
        int count = 0;
        // check if there is an existing continuous subarray
        for (int i = 0; i < cum_sum.size(); i++){
            if (cum_sum[i] == k) count++;
        }
        
        for (int i = 1; i < cum_sum.size(); i++){
            for (int j = i; j < cum_sum.size(); j++){
                if (cum_sum[j] - cum_sum[i-1] == k) count++;
            }
        }
        return count;
    }
};

/* Method 2: Cumulative Sum On the Go */
// time complexity O(n^2)
// space complexity O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); start++) {
            int sum=0;
            for (int end = start; end < nums.size(); end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
};

/* Method 3: Using Hashmap */
// time complexity O(n)
// space complexity O(n)
/*
basic idea:

If the cumulative sum (repreesnted by sum[i] sum[j] for sum upto i-th and j-th index) upto two indices is the same, 
the sum of the elements lying in between those indices is zero. 

Extending the same thought further, if the cumulative sum upto two indices, say ii and jj is at a difference of kk 
(i.e. if sum[i] - sum[j] = k) the sum of elements lying between indices ii and jj is kk.
*/
class Solution {
public:
    int subarraySum(vector<int>& A, int k) {
        unordered_map<int, int> hash;
        int sum = 0, ans = 0;
        hash[0] = 1;
        for(int a : A) {
            sum += a;
            ans += hash[sum - k];
            hash[sum]++;
        }
        return ans;
    }

};