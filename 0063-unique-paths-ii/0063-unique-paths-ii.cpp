class Solution {
public:
    int dp[105][105];
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        memset(dp,-1,sizeof(dp));
        return fun(og,0,0);
    }
    int fun(vector<vector<int>>& og,int i,int j){
        if(i==og.size()-1 && j==og[0].size()-1 && !og[i][j]){
            return 1;
        }
        if(i>=og.size() || j>=og[0].size()) return 0;
        
        if(og[i][j]) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=fun(og,i+1,j) + fun(og,i,j+1);
    }
};