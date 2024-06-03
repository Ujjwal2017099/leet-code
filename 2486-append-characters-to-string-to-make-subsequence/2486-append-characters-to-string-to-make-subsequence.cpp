class Solution {
public:
    int appendCharacters(string s, string t) {
        int t_i=0;
        for(int i=0;i<s.size();i++){
            // if(t_i==t.size()-1) return 0;
            if(t_i == t.size()) break;
            if(t[t_i]==s[i]){
                t_i++;
            }
        }
        
        return t.size()-t_i;
    }
};