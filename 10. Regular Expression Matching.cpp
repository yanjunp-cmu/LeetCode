class Solution {
private:
    bool helper(const string &s, const string &p, int sS, int pS)
    {
        int sSize = s.size(), pSize = p.size(), i, j; 
        if(pS==pSize) return sS ==sSize; // if p goes to its end, then only if s also goes to its end to return true;
        
        if(p[pS+1]!='*') {
           if( sS<sSize && (p[pS]==s[sS] || p[pS] == '.')) return helper(s, p, sS+1, pS+1);
        }
        else {
            if(helper(s, p, sS,pS+2)) return true;
            while(sS<sSize && (p[pS]==s[sS] || p[pS] == '.')) if(helper(s,p, ++sS, pS+2)) return true;
        }
        return false;
    }

public:
    bool isMatch(string s, string p) {
       return helper(s, p, 0, 0); 
    }
};