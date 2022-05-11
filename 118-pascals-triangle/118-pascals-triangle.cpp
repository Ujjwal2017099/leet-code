class Solution {
    // vector<int> dp[31] ;
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> dp(n);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j <= i ; j++){
                if(j==0 or j==i){dp[i].push_back(1);continue;}
                dp[i].push_back(dp[i-1][j-1] + dp[i-1][j]);
            }
            
            // ans.push_back(dp[i]);
        
        
        return dp;
    }
};