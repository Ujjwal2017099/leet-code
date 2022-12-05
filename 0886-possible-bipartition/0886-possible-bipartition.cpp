class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<vector<int>> g(n+1);
        for(vector<int> t:d){
            int u = t[0], v = t[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++){
            
            bool f = 0; 
            if(!vis[i]) f = iscycle(g,vis,i,0,0);
            if(f) return 0;
        }
        return 1;
    }
    bool iscycle(vector<vector<int>>& g,vector<int>& vis,int i,int par,int l){
        vis[i] = l;
        for(int x:g[i]){
            if(!vis[x]){
                bool f = iscycle(g,vis,x,i,l+1);
                if(f) return 1;
            }
            else if(x!=par){
                int a = l - vis[x];
                if(!(a&1))
                return 1;
            }
        }
        return 0;
    }
};