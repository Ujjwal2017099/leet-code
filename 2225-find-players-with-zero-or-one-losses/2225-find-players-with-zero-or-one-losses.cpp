class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        map<int,int> g;
        for(int i=0;i<m.size();i++){
            g[m[i][1]]++;
            g[m[i][0]];
        }
        vector<vector<int>> ans(2);
        for(auto it:g){
            if(it.second == 0) ans[0].push_back(it.first);
            if(it.second == 1) ans[1].push_back(it.first);
        }
        return ans;
    }
};