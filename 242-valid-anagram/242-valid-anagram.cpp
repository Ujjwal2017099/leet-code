class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        int as[26]={0};
        int at[26]={0};
        
        for(int i=0;i<s.length();i++){
            as[s[i]-'a']++;
            at[t[i]-'a']++;
        }
        
        for(int i=0;i<=25;i++){
            if(as[i]!=at[i]) return false;
        }
        
        return true;
    }
};