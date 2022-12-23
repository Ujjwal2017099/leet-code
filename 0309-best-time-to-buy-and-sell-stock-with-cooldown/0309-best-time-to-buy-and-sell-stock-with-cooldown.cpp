class Solution {
public:
    int  dp[2][2][5001];
    int maxProfit(vector<int>& p) {
        memset(dp,-1,sizeof(dp));
        return fun(p,0,0,0);
    }
    int fun(vector<int>& p,int curr,int c,int buy){
        if(curr==p.size()){
            return 0;
        }
        if(dp[buy][c][curr]!=-1) return dp[buy][c][curr];
        if(buy || c){
            if(c) return fun(p,curr+1,0,0);
            
            int x = fun(p,curr+1,1,0) + p[curr];
            int y = fun(p,curr+1,0,1);
            
            return dp[buy][c][curr] = max(x,y);
        }else{
            int x = fun(p,curr+1,0,1) - p[curr];
            int y = fun(p,curr+1,0,0);
            
            return dp[buy][c][curr] = max(x,y);
        }
    }
};