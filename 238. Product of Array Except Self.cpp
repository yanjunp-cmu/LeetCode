/*
 * Two passes with O(1) extra space
 * forward pass:
 *      keep track of the product to the left of i-th element
 * backward pass:
 *      multiply the previous result with the product to the right of i-th element
 * One thing to note:
 *      need a temp variable to keep track of the product to the right
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int tmp = 1;
        // forward pass
        // keeps track of all product to the left of i-th element
        for (int i = 1; i < nums.size(); i++){
            result[i] = nums[i-1] * result[i-1];
        }
        // backward pass
        // multiply the product to the right of i-th element
        for (int i = nums.size()-2; i >= 0; i--){
            // when backward pass, need a temp variable to store the product to the right
            tmp *= nums[i+1];
            result[i] = tmp * result[i];
        }
        return result;
    }
};