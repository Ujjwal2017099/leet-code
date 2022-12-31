class Solution {
public:
    int cnt=0;
    int k=0;
    int dp[21][21];
    int uniquePathsIII(vector<vector<int>>& g) {
        int in=0,jn=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1) {
                    in=i;jn=j;
                    k++;
                }
                if(g[i][j]==0) k++;
            }
        }
        vector<vector<int>> vis(g.size(),vector<int>(g[0].size(),0));
        // memset(dp,-1,sizeof(dp));
        fun(g,in,jn,vis,0);
        return cnt;
    }
    void fun(vector<vector<int>>& g,int i,int j,vector<vector<int>>& vis,int s){
        if(i==g.size() || j==g[0].size()) return ;
        if(i<0 || j<0) return ;
        if(g[i][j]==-1) return ;
        // if(dp[i][j]!=-1) return dp[i][j];
        if(vis[i][j]) return ;
        if(g[i][j]==2){
            if(s==k) {
                cnt++;
                return ;
            }
            return ;
        }
        vis[i][j]=1;
        fun(g,i+1,j,vis,s+1);
        fun(g,i,j+1,vis,s+1);
        fun(g,i-1,j,vis,s+1);
        fun(g,i,j-1,vis,s+1);
        vis[i][j]=0;
        // return dp[i][j]=a+b+c+d;
    }
};