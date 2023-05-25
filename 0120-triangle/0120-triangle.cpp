class Solution {
public:
    vector<vector<int>> dp;
    int minimumTotal(vector<vector<int>>& t) {
        dp.resize(t.size(),vector<int>(t.size(),-1));
        return fun(t,0,0);
    }
    int fun(vector<vector<int>>& t,int i,int j){
        if(i==t.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int x=fun(t,i+1,j)+t[i][j];
        int y=fun(t,i+1,j+1)+t[i][j];
        
        return dp[i][j]= min(x,y);
    }
};