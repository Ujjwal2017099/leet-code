class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<vector<string>> ans;
        map<vector<int>,vector<int>> mp;
        for(int i=0;i<s.size();i++){
            vector<int> t(26,0);
            for(char c:s[i]){
                t[c-'a']++;
            }
            mp[t].push_back(i);
        }
        for(auto& it:mp){
            vector<string> x;
            for(int i:it.second){
                x.push_back(s[i]);
            }
            ans.push_back(x);
        }
        return ans;
    }
};