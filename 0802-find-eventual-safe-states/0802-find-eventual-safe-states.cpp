class Solution {
public:
    set<int> ans;
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
            vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            fun(g,vis,i);
        }
        vector<int> ot;
        for(int i:ans){
            ot.push_back(i);
        }
        return ot;
    }
    int fun(vector<vector<int>>& g,vector<int>& vis,int i){
        if(vis[i]){
            if(ans.find(i)==ans.end() && !g[i].empty()) return 0;
            return 1;
        }
        vis[i] = 1;
        if(g[i].empty()){
            ans.insert(i);
            return 1;
        }
        for(int x:g[i]){
            int t = fun(g,vis,x);
            if(t==0) return 0;
        }
        ans.insert(i);
        return 1;
    }
};