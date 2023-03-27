class Solution {
public:
    int ans=1e9;
    vector<vector<int>> d = {{0,1},{1,0}};
    vector<vector<int>> vis;
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        vis.resize(n,vector<int>(m,0));
        fun(g,0,0,0);
        return ans;
    }
    void fun(vector<vector<int>>& g,int i,int j,int sum){
        int n=g.size(),m=g[0].size();
        if(i>=n || j>=m) return;
        if(i==n-1 && j==m-1){
            sum+=g[i][j];
            ans=min(sum,ans);
            return;
        }
        if(vis[i][j] && vis[i][j]<=sum) return;
        
        vis[i][j]=sum;
        for(int x=0;x<2;x++){
            fun(g,i+d[x][0],j+d[x][1],sum + g[i][j]);
        }
    }
    
};