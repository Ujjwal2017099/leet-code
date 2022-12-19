class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        vector<vector<int>> g(n);
        for(auto it:e){
            int u=it[0],v = it[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<bool> vis(n,0);
        
        return fun(g,vis,-1,s,d);
    }
    bool fun(vector<vector<int>>& g,vector<bool>& vis,int par,int i,int d){
        if(i==d){
            return 1;
        }
        vis[i] = 1;
        for(int x:g[i]){
            if(x!=par && !vis[x]){
                bool f= fun(g,vis,i,x,d);
                if(f) return 1;
            }
        }
        return 0;
    }
};