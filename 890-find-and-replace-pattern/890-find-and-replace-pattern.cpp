class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,bool> vis;
        unordered_map<char,char> check1;
        unordered_map<char,char> check2;
        vector<string> ans;
        int i = 0;
        for(string s:words){
            if(s.length() == pattern.length()){
                i=0;
                for(char c:pattern){
                    if(vis[c]){
                        if(check1[c]!=s[i] or check2[s[i]] != c) break;
                    }else{
                        vis[c]=true;
                        check1[c] = s[i];
                        check2[s[i]] = c;
                    }
                    i++;
                }
                if(i==pattern.length() and check1.size()==check2.size()) ans.push_back(s);
                vis.clear();
                check1.clear();
                check2.clear();
            }
        }
        
        return ans;
    }
};