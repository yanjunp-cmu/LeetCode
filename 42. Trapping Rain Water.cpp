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