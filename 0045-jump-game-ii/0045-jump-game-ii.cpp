class Solution {
public:
    int jump(vector<int>& n) {
        vector<int> dp(n.size(),0);
        for(int i=n.size()-2;i>=0;i--){
            for(int j=n[i];j>0;j--){
                if(j+i==n.size()-1){
                    dp[i] = 1;
                }
                else if(j+i<n.size()){
                    if(dp[j+i]){
                        if(dp[i]==0) dp[i] = dp[i+j]+1;
                        else dp[i] = min(dp[i],dp[i+j]+1);
                    }
                }
            }
        }
        // for(int i:dp) cout<<i<<" ";
        return dp[0];
    }
};