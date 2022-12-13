class Solution {
public:
    int dp[101][101];
    int minFallingPathSum(vector<vector<int>>& m) {
        int ans = INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m[0].size();i++){
            ans = min(ans,fun(m,0,i));
        }
        return ans;
    }
    int fun(vector<vector<int>>& m,int i,int j){
        if(i==m.size()-1){
            return m[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int a = m[i].size();
        int x=INT_MAX,y=INT_MAX,z=fun(m,i+1,j)+m[i][j];
        if(j-1>=0) x = fun(m,i+1,j-1) + m[i][j];
        if(j+1<a) y = fun(m,i+1,j+1) + m[i][j];
        
        return dp[i][j] = min(min(x,y),z);
    }
};