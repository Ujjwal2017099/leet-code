class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string s1,t1;
        
        for(char c:s){
            if(c == '#' and !s1.empty()) {s1.pop_back();continue;}
            else if(s1.empty() and c == '#') continue;
            s1 += c;
        }
        for(char c:t){
            if(c == '#' and !t1.empty()) {t1.pop_back();continue;}
            else if(t1.empty() and c == '#') continue;
            t1 += c;
        }
        
        return s1 == t1;
    }
};