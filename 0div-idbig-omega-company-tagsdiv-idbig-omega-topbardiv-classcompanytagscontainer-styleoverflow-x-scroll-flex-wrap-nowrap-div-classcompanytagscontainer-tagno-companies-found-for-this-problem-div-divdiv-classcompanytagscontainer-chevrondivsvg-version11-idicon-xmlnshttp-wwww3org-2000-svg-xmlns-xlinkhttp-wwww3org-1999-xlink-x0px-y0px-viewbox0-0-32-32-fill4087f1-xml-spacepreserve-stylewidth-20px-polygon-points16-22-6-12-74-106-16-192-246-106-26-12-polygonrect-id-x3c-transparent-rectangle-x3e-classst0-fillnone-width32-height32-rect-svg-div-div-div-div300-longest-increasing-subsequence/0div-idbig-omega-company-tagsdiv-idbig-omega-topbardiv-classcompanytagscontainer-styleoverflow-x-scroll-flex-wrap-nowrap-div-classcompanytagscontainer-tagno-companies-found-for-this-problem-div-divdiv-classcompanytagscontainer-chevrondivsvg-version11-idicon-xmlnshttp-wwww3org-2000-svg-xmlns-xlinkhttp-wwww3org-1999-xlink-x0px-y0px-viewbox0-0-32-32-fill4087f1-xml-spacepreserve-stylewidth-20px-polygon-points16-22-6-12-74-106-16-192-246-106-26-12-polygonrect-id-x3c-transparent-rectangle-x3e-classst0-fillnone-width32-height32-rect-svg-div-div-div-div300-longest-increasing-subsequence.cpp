class Solution {
public:
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& n) {
        dp.resize(n.size(),vector<int>(n.size(),-1));
        
        int ans=1;
        for(int i=0;i<n.size();i++){
            ans=max(ans,fun(n,i,i)+1);
        }
        return ans;
    }
    int fun(vector<int>& n,int i,int prev){
        if(i==n.size()){
            return 0;
        }
        if(dp[i][prev]!=-1) return dp[i][prev];
        
        if(n[i]<=n[prev]){
            int x=fun(n,i+1,prev);
            // int y=fun(n,i+1,i);
            
            return dp[i][prev]=x;
        }
        
        int x=fun(n,i+1,i)+1;
        int y=fun(n,i+1,prev);
        
        return dp[i][prev] = max(x,y);
    }
};