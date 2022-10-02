class Solution {
public:
    int dp[102][102];
    int rob(vector<int>& n) {
        memset(dp,0,sizeof(dp));
        for(int l=0;l<n.size();l++){
            for(int i=0;i<n.size();i++){
                if(i!=l+1){
                    dp[l+1][i+1] = max(dp[l+1][i],max(dp[l+1][l+1]+n[i],dp[l][i+1]));
                }else{
                    dp[l+1][i+1] = max(dp[l][i+1],dp[l+1][i]);
                }
            }
        }
        // for(int l=0;l<=n.size();l++){
        //     for(int i=0;i<=n.size();i++){
        //         cout<<dp[l][i]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n.size()][n.size()];
    }
};