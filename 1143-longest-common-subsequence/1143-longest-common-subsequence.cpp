class Solution {
public:
    int dp[1000][1000];
    int longestCommonSubsequence(string t1, string t2) {
        memset(dp,-1,sizeof(dp));
        return fun(t1,t2,0,0);
    }
    int fun(string& t1,string& t2,int i,int j){
        if(i==t1.size()){
            return 0;
        }
        if(j==t2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(t1[i]==t2[j]){
            return fun(t1,t2,i+1,j+1) + 1;
        }
        
        int x = fun(t1,t2,i+1,j);
        int y = fun(t1,t2,i,j+1);
        
        return dp[i][j]=max(x,y);
    }
};