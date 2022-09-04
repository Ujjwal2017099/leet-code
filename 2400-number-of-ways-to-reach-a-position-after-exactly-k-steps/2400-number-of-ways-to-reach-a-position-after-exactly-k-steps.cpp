const int mod = 1e9+7;
class Solution {
public:
    vector<vector<int>> dp;
    int K;
    int numberOfWays(int s, int e, int k) {
        K = k;
        dp.resize(2*(K)+s+1,vector<int>(K+1,-1));
        return fun(s,e,k);
        // return cnt;
    }
    int fun(int s,int e,int k){
        if(k==0){
            if(s == e) return 1;
            return 0;
        }
        if(dp[s+K][k]!=-1) return dp[s+K][k];
        long long cnt = 0 ;
        cnt += fun(s+1,e,k-1)%mod;
        cnt += fun(s-1,e,k-1)%mod;
        
        return dp[s+K][k] = cnt%mod;
    }
};
