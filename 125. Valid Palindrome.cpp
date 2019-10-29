class Solution {
public:
    bool isPalindrome(string s) 
    {
        if(s.empty()) return true;
        
        int i = 0, j = s.size()-1;
        
        while(i < j)
        {
            char ch1 = s[i];
            if( !( ('A'<=ch1 && ch1<='Z') || ('a'<=ch1 && ch1<='z') || ('0'<=ch1 && ch1<='9') ) ){ 
                i++; 
                continue; 
            }
            
            char ch2 = s[j];
            if( !( ('A'<=ch2 && ch2<='Z') || ('a'<=ch2 && ch2<='z') || ('0'<=ch2 && ch2<='9') ) ){ 
                j--; 
                continue; 
            }
            
            if( !((ch1 == ch2) || 
                (ch1 >= 'A' && ch2 >= 'A' && abs(ch1-ch2) == 'a'-'A')) // checks upper and lower cases
                ){
                return false;
            }
            i++; j--;
        }
        
        return true;
    }
};