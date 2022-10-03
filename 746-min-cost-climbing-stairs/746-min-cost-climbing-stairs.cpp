class Solution {
public:
    int dp[1005];
    int minCostClimbingStairs(vector<int>& c) {
        memset(dp,-1,sizeof(dp));
        return min(fun(c,0),fun(c,1));
    }
    int fun(vector<int>& c,int i){
        if(i>=c.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int a=fun(c,i+1) + c[i];
        int b=fun(c,i+2) + c[i];
        
        return dp[i]=min(a,b);
    }
};