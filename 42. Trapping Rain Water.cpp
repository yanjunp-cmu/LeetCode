/*
 * Stack method:
        traverse the array:
            if the current height is larger than the top of stack
                pop the top of the stack, calculate the amount of water trapped:
                    iterate through the stack until current is <= top
 */
class Solution {
public:
    int trap(vector<int>& height)
    {
        if(height.empty()) return 0;
        
        int ans = 0;
        int current = 0;
        
        stack<int> st;
        
        while (current < height.size()){
            while (!st.empty() && height[current] > height[st.top()]){
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int dis = current - st.top() - 1;
                int bounded_hei = min (height[current], height[st.top()]) - height[top];
                ans += dis * bounded_hei;
            }
            st.push(current);
            current++;
        }
                
        return ans;
    }
};

/*
 * Double pointer method:
 * The amount of water trapped depends on the length of the shorter wall
 * two pointers moving toward each other while maintaining a left_max and a right_max
 */
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty() || height.size() == 1)
            return 0;
        int left = 0;
        int right = height.size()-1;
        int result = 0;
        int left_max = height[left];
        int right_max = height[right];
        
        while (left < right){
            if (height[left] <= height[right]){
                if (height[left + 1] > left_max){
                    left_max = height[left+1];
                } else {
                    result += left_max - height[left+1];
                }
                left++;
            } else {
                if (height[right -1] > right_max){
                    right_max = height[right-1];
                } else {
                    result += right_max - height[right-1];
                }
                right--;
            }
        }
        
        return result;
    }
};