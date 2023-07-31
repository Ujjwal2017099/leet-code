class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        vector<vector<int>> dp(m.size(),vector<int>(m[0].size()+1,0));
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]=='1') dp[i][j+1]=1;
            }
        }
        for(int i=0;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                dp[i][j] += dp[i][j-1];
            }
        }
        int ans=0;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                int a=j;
                for(int k=j+1;k<dp[0].size();k++){
                    j=k-1;
                    if(dp[i][k]-dp[i][a]==k-a){
                        int x=k-a;
                        for(int y=i;y<dp.size() && x;y++){
                            if(dp[y][k]-dp[y][a]==k-a) x--;
                            else break;
                        }
                        for(int y=i-1;y>=0 && x;y--){
                            if(dp[y][k]-dp[y][a]==k-a) x--;
                            else break;
                        }
                        if(!x) ans=max(ans,(k-a)*(k-a));
                        else {break;}
                    }else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};