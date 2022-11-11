class Solution {
public:
    int dp[100][10005];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int numSquares(int n) {
        vector<int> v;
        for(int i=1;i<=sqrt(n);i++){
            if(i*i>n) break;
            v.push_back(i*i);
        }
        return fun(v,0,n);
    }
    int fun(vector<int>& v,int i,int n){
        if(n==0){
            return 0;
        }
        if(i==v.size()){
            return 1e7;
        }
        if(dp[i][n]!=-1) return dp[i][n];
        
        int x = 1e7; if(n-v[i]>=0) x = fun(v,i,n-v[i])+1;
        int y = fun(v,i+1,n);
        int z = 1e7; if(n-v[i]>=0) z = fun(v,i+1,n-v[i])+1;
        
        return dp[i][n]=min(x,min(y,z));
    }
};