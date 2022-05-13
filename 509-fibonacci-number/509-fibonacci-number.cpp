class Solution {
    int *dp;
public:
    int fib(int n) {
        dp = new int[50];
        dp[0] = 0;
        dp [1] = 1;
        
        for(int i = 2 ; i <= n ; i++)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};