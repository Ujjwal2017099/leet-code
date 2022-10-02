class Solution {
public:
    int dp[102][102];
    int rob(vector<int>& n) {
        memset(dp,-1,sizeof(dp));
        return fun(n,0,1);
    }
    int fun(vector<int>& n,int i,int l){
        if(i==n.size()){
            return 0;
        }
        if(dp[i][l]!=-1){
            return dp[i][l];
        }
        int x=0,y=0;
        if(i==l+1){
            x = fun(n,i+1,l);
        }else{
            int a = fun(n,i+1,i) + n[i];
            int b = fun(n,i+1,l);
            y = max(a,b);
        }
        return dp[i][l]=max(x,y);
    }
};