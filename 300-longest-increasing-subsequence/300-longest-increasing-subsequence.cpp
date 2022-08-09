class Solution {
public:
    int dp[2510][2510];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int lengthOfLIS(vector<int>& nums) {
        int a= fun(nums,0,-1);
        return a;
    }
    int fun(vector<int>& n,int i,int t){
        if(i==n.size()){
            return 0;
        }
        if(dp[i][t+1] != -1) return dp[i][t+1];
        
        int c = fun(n,i+1,t);
        if(t==-1 || n[i] > n[t]) c = max(c,1+fun(n,i+1,i));
        
        return dp[i][t+1] = c;
    }
};