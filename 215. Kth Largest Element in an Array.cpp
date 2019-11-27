/*
 * follow up solution:
 * 		quick select
 * partition: select a pivot point and put all smaller elements to the left
 				all larger elements to the right, return the correct pivot location
 * if the returned position is at k, then return index
 * if returned position is less than k, kth largest is to the right
 * if returned position is larger than k, kth largest is to the left
 */
class Solution {
public:
    int partition(vector<int>& nums, int l, int r) { 
	    int x = nums[r], i = l; 
	    // i indicates the first unswapped element that is larget than the pivot
	    for (int j = l; j <= r - 1; j++) { 
	        if (nums[j] <= x) { 
	            swap(nums[i], nums[j]); 
	            i++; 
	        } 
	    } 
	    // swap the first unswapped larger element with the pivot
	    swap(nums[i], nums[r]); 
	    return i; 
	} 

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> temp;
        int m = nums.size() - k;
        
        while (true){            
            if (l > r)
                return -1;
            
            int piv = partition(nums, l, r);
            
            if (piv == m)
                return nums[piv];
            else if (piv < m)
                l = piv + 1;
            else 
                r = piv - 1;      
        }
        
    }
};

/*
 * base solution: 
 * 		O(nlog(n)) sort then array access
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[](int A, int B){return A>=B;});
        return nums[k-1];
    }
};