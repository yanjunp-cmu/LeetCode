/*
 * use of stack and map
 * corner case where the stack is empty and the next parentheses is '),],}'
 */
class Solution {
private:
    unordered_map<char, char> p_map{
        {'(',')'},
        {'{','}'},
        {'[',']'}
    };
public:
    bool isValid(string s) {
        stack<char> p_stack;
        for (char c : s){
            if (c == '(' || c == '{' || c == '['){
                p_stack.push(c);
            } else {
                // corner case
                if(p_stack.empty())
                    return false;
                if (c == p_map[p_stack.top()])
                    p_stack.pop();
                else
                    return false;
            }
        }
        if(p_stack.empty()) return true;
        return false;
    }
};