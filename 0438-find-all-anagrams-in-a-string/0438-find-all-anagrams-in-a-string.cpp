class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int c1[26] = {0};
        int c2[26] = {0};
        for(char c:p){
            c1[c-'a']++;
        }
        if(p.size()>s.size()) return {};
        // for(char c:s){
        //     c2[c-'a']++;
        // }
        vector<int> ans;
        int f=0;
        int i;
        for(i=0;i<p.size();i++){
            if(c1[s[i]-'a']){
                f++;
                c1[s[i]-'a']--;
                c2[s[i]-'a']++;
            }
            else if(f){
                break;
            }
        }
        for(i;i<s.size();i++){
            if(c1[s[i]-'a']==0 && f){
                if(f==p.size()){
                    ans.push_back(i-f);
                    // for(int j=0;j<26;j++){
                    //     c1[j] += c2[j];c2[j]=0;
                    // }
                    // f=0;
                    // i--;
                }
                // else{
                    c1[s[i-f]-'a']++;
                    c2[s[i-f]-'a']--;
                    f--;i--;
                // }
            }else if(c1[s[i]-'a']){
                c1[s[i]-'a']--;
                c2[s[i]-'a']++;
                f++;
            }
        }
        if(f==p.size()){
            ans.push_back(s.size()-p.size());
        }
        return ans;
    }
};