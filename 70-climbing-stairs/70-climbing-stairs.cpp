class Solution {
public:
    int dp[50];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int climbStairs(int n) {
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        
        int a=climbStairs(n-1);
        int b=climbStairs(n-2);
        return dp[n]=a+b;
    }
};