/*
    use two stacks, one for count, one for character
*/

class Solution {
public:
    string decodeString(string s) {
        string result = "", tmp = "";
        if (s.size() == 0) return result;
        
        stack<int> k_stack;
        stack<char> str_stack;
        
        string clip = "";
        
        for(int i = 0; i < s.size(); i++){
            // when the current char is a num
            int count = 0; 
  
            // If number, convert it into number 
            // and push it into integerstack. 
            if (s[i] >= '0' && s[i] <='9') 
            { 
                while (s[i] >= '0' && s[i] <= '9') 
                { 
                    count = count * 10 + s[i] - '0'; 
                    i++; 
                } 
                i--; 
                k_stack.push(count); 
            } 
            // 
            else if (s[i] == '[') {
                // this section deals with consecutive '['s
                if (s[i-1] >= '0' &&s[i-1] <= '9' ) str_stack.push('[');
                // when consecutive '[' appears, manually insert 1
                else {
                    k_stack.push(1);
                    str_stack.push('[');
                }
            }
            
            // 
            else if (s[i] == ']'){
                tmp = "";
                count = 0;
                
                if (!k_stack.empty()) {
                    count = k_stack.top();
                    k_stack.pop();
                }
                // build the inner most string
                while (str_stack.top() != '[' && !str_stack.empty()){
                    tmp = str_stack.top() + tmp;
                    str_stack.pop();
                }
                // pop the '[' once finish building the string
                if (!str_stack.empty() && str_stack.top() == '[') str_stack.pop(); 
                // append the temporary string to result
                // repeat the result count times
                for (int j = 0; j < count; j++){
                    result += tmp;
                }
                // push result characters into the stack
                for (int j = 0; j < result.size(); j++){
                    str_stack.push(result[j]);
                }
                // clear result
                result = "";
                // if s[i] is a character
            } else {
                str_stack.push(s[i]);
            }
            
        }
        // build final string from stack
        while (!str_stack.empty()){
            result = str_stack.top() + result;
            str_stack.pop();
        }
        
        
        return result;
    }
};