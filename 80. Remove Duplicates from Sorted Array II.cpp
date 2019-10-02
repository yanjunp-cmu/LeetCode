class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();
        // j is the position count in nums
        int j = 2;
        int count;
        // initialize counter 
        if(nums[0] == nums[1])
            count = 2;
        else 
            count = 1;
        // loop the vector
        // if the current is not the same as the previous or the counter is 1
        //      set j-th element to current
        // else if two elements are the same and the ccounter is 1
        //      increment the counter and set j-th element to current
        // increment j
        for(int i=2; i<nums.size(); i++)
        {
            if(nums[i] != nums[i-1] || count == 1)
            {
                if(nums[i] == nums[i-1])
                    count = 2;
                else
                    count = 1;
                nums[j++] = nums[i];                
            }
        }
        return j;
    }
};