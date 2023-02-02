class Solution {
public:
    bool isAlienSorted(vector<string>& w, string o) {
        map<char,int> mp;
        for(int i=0;i<o.size();i++){
            mp[o[i]] = i;
        }
        for(int i=1;i<w.size();i++){
            for(int j=0;j<min(w[i].size(),w[i-1].size());j++){
                if(mp[w[i][j]] > mp[w[i-1][j]]) break;
                if(mp[w[i][j]] == mp[w[i-1][j]] && j == min(w[i].size(),w[i-1].size())-1 && w[i].size() < w[i-1].size())
                    return 0;
                if(mp[w[i][j]] < mp[w[i-1][j]]) return 0;
            }
        }
        return 1;
    }
};