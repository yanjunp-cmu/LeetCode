class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;               
        int n = words.size(), charCnt = 0, L = 0; // L: index of beginnig word in row
        
        for(int i = 0; i < n; i++){
            // Calc minimum length of string if include words[i]. At least (i - L) spaces are needed to seperate words
            int extend = charCnt + words[i].size() + i - L;    
            if(extend <= maxWidth){
                charCnt += words[i].size();                
                if(i == n - 1) result.push_back(getPaddedStr(words, L, i, true, charCnt, maxWidth));
            }else{
                int R = i - 1;
                // L == R single word row, left justify 
                result.push_back(getPaddedStr(words, L, R, L == R, charCnt, maxWidth)); 
                L = i--; charCnt = 0;            
            }
        }  
        
        return result;
    }
  
    string getPaddedStr(vector<string>& words, int l, int r, bool leftJustified, int charCnt, int maxWidth){
        string ans;
        int spaceCnt = maxWidth - charCnt;             
        int evenPadding = leftJustified ? 1 : spaceCnt / (r - l);
        int nLeft = leftJustified ? 0 : spaceCnt % (r - l); // extra one space padding needed for nLeft words
        
        for(int i = l; i < r; i++) ans += words[i] + string(evenPadding + (i - l < nLeft), ' ');  
        ans += words[r];
        
        return ans + string(maxWidth - ans.size(), ' ');
    } 
};