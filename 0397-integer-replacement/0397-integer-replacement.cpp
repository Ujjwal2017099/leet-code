class Solution {
public:
    map<int,int> dp;
    int integerReplacement(long long n) {
        if(n==1){
            return 0;
        }    
        if(dp[n]) return dp[n];
        if(n&1){
            return dp[n] = min(integerReplacement(n-1),integerReplacement(n+1))+1;
        }
        return dp[n] = integerReplacement(n>>1)+1;
    }
    
};