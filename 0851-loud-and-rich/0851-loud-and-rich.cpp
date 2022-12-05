class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& r, vector<int>& q) {
        int n = q.size();
        if(n==1) return q;
        vector<vector<int>> g(n);
        for(vector<int> t:r){
            int u = t[0],v = t[1];
            g[v].push_back(u);
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            int mn = dfs(g,vis,q,i);
            ans[i] = mn;      
        }
        return ans;
    }
    int dfs(vector<vector<int>>& g,vector<int>& vis,vector<int>& q,int i){
        if(g[i].empty() || vis[i]){
            return i;   
        }
        vis[i] =1;
        int mn = i;
        for(int x:g[i]){
            int a = dfs(g,vis,q,x);
            mn = q[mn] > q[a] ? a : mn;
        }
        return mn;
    }
};