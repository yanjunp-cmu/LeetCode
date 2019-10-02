class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // make sure that the short array is the first vector processed
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int a = 0, b = nums1.size(), mid1, mid;
        int left_max1, left_max2, right_min1, right_min2;
        bool isEven = ((nums1.size() + nums2.size()) %2 == 0);
        
        while (a <= b){
            mid1 = a + (b - a) / 2;
            // the definition of the left part:
            //      a to mid-1
            // the definition of the right part:
            //      mid to b
            
            // takes care of left_max of the first vector
            if (mid1 == 0)
                left_max1 = INT_MIN;
            else
                left_max1 = nums1[mid1-1];
            // takes care of the right_min of the first vector
            if (mid1 == nums1.size())
                right_min1 = INT_MAX;
            else
                right_min1 = nums1[mid1];
            
            // calculate how many numbers should be after or before mid1
            if(isEven)
                mid = (nums1.size() + nums2.size())/2 - mid1;
            else 
                mid = (nums1.size() + nums2.size())/2 - mid1 + 1;
            // left part of the longer vector
            if (mid == 0)
                left_max2 = INT_MIN;
            else
                left_max2 = nums2[mid-1];
            // right part of the longer vector
            if (mid == nums2.size())
                right_min2 = INT_MAX;
            else
                right_min2 = nums2[mid];
            
            if(right_min2 >= left_max1 && right_min1 >= left_max2){
                if(isEven) 
                    return ((double) max(left_max1, left_max2) + (double) min(right_min1, right_min2)) / 2.0;
                else 
                    return max(left_max1, left_max2);
            }
            else if (left_max1 > right_min2){
                b = mid1 - 1;
            }
            else{
                a = mid1 + 1;
            }
        }
        return 0;
    }
};