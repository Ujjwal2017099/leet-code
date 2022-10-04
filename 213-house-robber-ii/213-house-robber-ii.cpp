class Solution {
public:
    int dp[105][105][2];
    int rob(vector<int>& n) {
        memset(dp,-1,sizeof(dp));
        return fun(n,0,103,0);
    }
    int fun(vector<int>& n,int f,int l,int i){
        if(i==n.size()){
            return 0;
        }
        
        if(l>=0 and dp[i][l][f] != -1){
            return dp[i][l][f];
        }
        if(i==l+1 or (i==n.size()-1 and f)){
            int x = fun(n,f,l,i+1);
            
            return dp[i][l][f]=x;
        }else{
            if(i==0) f=1;
            int x = fun(n,f,i,i+1) + n[i];
            if(i==0) f=0;
            int y = fun(n,f,l,i+1);
            
            return dp[i][l][f]=max(x,y);
        }
    }
};