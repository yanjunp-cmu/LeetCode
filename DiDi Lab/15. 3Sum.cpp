/*
 * Approach: three pointers
 * first sort the vector
 * then first complementary of nums[left]
 * skip duplicates when solution found
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int>> res;
        
        if (N < 3)
            return res;
        
        vector<int> triplet(3);  
        
        int left, mid, right;
        
        for (left = 0; left < N-2; ){
            mid = left + 1;
            right = N-1;
            int target = -nums[left];
            
            while (mid < right){
                if (nums[mid] + nums[right] == target){
                    triplet = {nums[left], nums[mid], nums[right]};
                    res.push_back(triplet);
                    while (mid < N && nums[mid] == triplet[1])
                        mid++;
                    while (right >= 0 && nums[right] == triplet[2])
                        right--;
                } else if (nums[mid] + nums[right] < target){
                    mid++;
                } else {
                    right--;
                }
            }
            
            if (nums[left+1] == nums[left]){
                int last_left = nums[left];
                while (left < N && nums[left] == last_left)
                    left++; 
            } else {
                left++;
            }
        }
        return res;
    }
};