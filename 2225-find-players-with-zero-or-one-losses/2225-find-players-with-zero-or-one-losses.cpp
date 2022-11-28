class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        map<int,int> g;
        for(int i=0;i<m.size();i++){
            g[m[i][1]]++;
        }
        vector<set<int>> ans(2);
        for(vector<int> t:m){
            int a = t[0],b = t[1];
            if(g[a]==0) ans[0].insert(a);
            else if(g[a]==1) ans[1].insert(a);
            if(g[b]==1) ans[1].insert(b);
        }
        vector<vector<int>> t1(2);
        int i=0;
        for(set<int> t:ans){
            for(int it:t) t1[i].push_back(it);
            i++;
        }
        return t1;
    }
};