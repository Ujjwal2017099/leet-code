class Solution {
public:
    vector<vector<int>> dp;
    int maxMoves(vector<vector<int>>& g) {
        int ans=0;
        dp.resize(g.size(),vector<int>(g[0].size(),-1));
        for(int i=0;i<g.size();i++){
            ans = max(ans,fun(g,i,0,0));
        }
        return ans;
    }
    int fun(vector<vector<int>>& g,int i,int j,int prev){
        if(i<0 || i>=g.size() || j<0 || j>=g[0].size()){
            return -1;
        }
        if(g[i][j] <= prev) return -1;
        if(dp[i][j]!=-1) return dp[i][j];
        int x = fun(g,i,j+1,g[i][j]) + 1;
        int y = fun(g,i-1,j+1,g[i][j]) + 1;
        int z = fun(g,i+1,j+1,g[i][j]) + 1;
        
        return dp[i][j] = max(x,max(y,z));
    }
};