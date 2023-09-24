class Solution {
public:
    double champagneTower(int p, int qr, int qg) {
        vector<vector<double>> dp(101,vector<double>(101,0));
        
        dp[0][0]=(double)p;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j]>1.0){
                    dp[i+1][j] += (dp[i][j]-1)/2.0;
                    dp[i+1][j+1] += (dp[i][j]-1)/2.0;
                    dp[i][j]=1;
                }
            }
        }
        // for(int i=0;i<100;i++){
        //     for(int j=0;j<=i;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[qr][qg];
    }
};