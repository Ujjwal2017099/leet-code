class Solution {
public:
    int dp[10005];
    bool canJump(vector<int>& n) {
        memset(dp,-1,sizeof(dp));
        return fun(n,0);
    }
    bool fun(vector<int>& n,int i){
        if(i>=n.size()) return 0;
        if(i==n.size()-1) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        int x = n[i];
        
        bool f=0;
        for(int j=1;j<=x;j++){
            f|=fun(n,i+j);
            if(f) return dp[i]=1;
        }
        return dp[i]=f;
    }
};