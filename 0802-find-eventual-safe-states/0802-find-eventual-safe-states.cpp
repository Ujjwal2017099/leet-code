class Solution {
public:
    vector<int> ans;
    map<int,bool> mp;
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            fun(g,vis,i);
        }
        // vector<int> ot;
        // for(int i:ans){
        //     ot.push_back(i);
        // }
        sort(ans.begin(),ans.end());
        return ans;
    }
    int fun(vector<vector<int>>& g,vector<int>& vis,int i){
        if(vis[i]){
            if(!mp[i] && !g[i].empty()) return 0;
            return 1;
        }
        vis[i] = 1;
        if(g[i].empty()){
            ans.push_back(i);
            mp[i] = 1;
            return 1;
        }
        for(int x:g[i]){
            int t = fun(g,vis,x);
            if(t==0) return 0;
        }
        ans.push_back(i);
        mp[i]=1;
        return 1;
    }
};