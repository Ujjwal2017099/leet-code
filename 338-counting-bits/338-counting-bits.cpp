class Solution {
    vector<int> dp;
public:
    Solution(){
        dp.resize(100000+2,0);
    }
    vector<int> countBits(int n) {
        
        for(int i=0 ; i <= n ;i++)
            fun(i);
        vector<int> ans(dp.begin(),dp.begin()+n+1);
        return ans;
    }
    int fun(int n){
        if(n==0) return 0;
        if(dp[n] != 0) return dp[n];
        if(n&1) dp[n] = fun(n>>1) + 1;
        else dp[n] = fun(n>>1);
        // return fun(n>>1);
        
        return dp[n];
    }
};