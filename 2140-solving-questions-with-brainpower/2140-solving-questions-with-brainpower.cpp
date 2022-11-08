class Solution {
public:
    long long dp[100005];
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return fun(questions,0);
    }
    long long fun(vector<vector<int>>& q,int i){
        if(i>=q.size()){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        long long x = fun(q,i+1);
        long long y = fun(q,i+q[i][1]+1) + q[i][0];
        
        return dp[i]=max(x,y);
    }
};