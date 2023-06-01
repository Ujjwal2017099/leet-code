class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        vector<vector<int>> d={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        if(g[0][0]) return -1;
        int n=g.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        int ans=INT_MAX;
        queue<vector<int>> q;
        q.push({0,0,1});
        vis[0][0]=1;
        while(!q.empty()){
            vector<int> x=q.front();q.pop();
            
            if(x[0]==n-1 && x[1]==n-1){
                ans=min(ans,x[2]);
                continue;
            }
            for(vector<int>& t:d){
                int u=x[0]+t[0],v=x[1]+t[1];
                if(u<0 || u>=n || v<0 || v>=n || vis[u][v] || g[u][v]) continue;
                q.push({u,v,x[2]+1});
                vis[u][v]=1;
            }
            
        }
        return ans==INT_MAX?-1:ans;
    }
};