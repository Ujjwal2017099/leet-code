class Solution {
public:
    set<vector<int>> ans;
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        vector<vector<int>> g(e.size()+1);   
        for(vector<int> t:e){
            g[t[0]].push_back(t[1]);
            g[t[1]].push_back(t[0]);
        }
        for(int i=1;i<=e.size();i++){
            vector<int> vis(e.size()+1,0);
            fun(g,vis,i,0);
        }
        for(int i=e.size()-1;i>=0;i--){
            if(ans.find(e[i]) != ans.end()) return e[i];
        }
        return e[0];
    }
    void fun(vector<vector<int>>& g,vector<int>& vis,int i,int par){
        vis[i]=1;
        for(int x:g[i]){
            if(vis[x] && x!=par) {
                ans.insert({i,x});
                ans.insert({x,i});
                // return;
            }
            if(!vis[x]) fun(g,vis,x,i);
        }
    }
};