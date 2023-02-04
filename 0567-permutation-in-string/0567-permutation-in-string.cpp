class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int c1[26] = {0};
        int c2[26] = {0};
        for(char c:s1){
            c1[c-'a']++;
        }
        for(char c:s2){
            c2[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(c1[i] > c2[i]){
                return 0;
            }
        }
        int t[26] = {0};
        int f=0;
        int i;
        for(i=0;i<s1.size();i++){
            if(c1[s2[i]-'a']){
                f++;
                c1[s2[i]-'a']--;
                t[s2[i]-'a']++;
            }
            else if(f){
                break;
            }
        }
        for(i;i<s2.size();i++){
            if(c1[s2[i]-'a']==0 && f){
                if(f==s1.size()) return 1;
                c1[s2[i-f]-'a']++;
                f--;i--;
            }else if(c1[s2[i]-'a']){
                c1[s2[i]-'a']--;
                f++;
            }
        }
        return f==s1.size() ? 1 : 0;
    }
};